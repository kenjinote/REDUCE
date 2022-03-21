/********************************************************************
 ********************************************************************
 **
 ** libhungarian by Cyrill Stachniss, 2004
 **
 **
 ** Solving the Minimum Assignment Problem using the
 ** Hungarian Method.
 **
 ** ** This file may be freely copied and distributed! **
 **
 ** Parts of the used code was originally provided by the
 ** "Stanford GraphGase", but I made changes to this code.
 ** As asked by  the copyright node of the "Stanford GraphGase",
 ** I hereby proclaim that this file are *NOT* part of the
 ** "Stanford GraphGase" distrubition!
 **
 ** This file is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied
 ** warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 ** PURPOSE.
 **
 ********************************************************************
 ********************************************************************/

// Adjusted by ACN to use a sparse representation. Quite a substantial set of
// changes really, but not to the underlying logic.

#include <cstdio>
#include <cstdlib>
#include "hungarian.h"

#define INF (0x7FFFFFFF)
#define verbose (0)

#define hungarian_test_alloc(X) do {if ((void *)(X) == nullptr) fprintf(stderr, "Out of memory in %s, (%s, line %d).\n", __FUNCTION__, __FILE__, __LINE__); } while (0)

edge_t *find_in_row(edge_t u, int n)
{   while (u != nullptr && u->col != n) u = u->next_in_row;
    return u;
}

edge_t *find_in_col(edge_t u, int n)
{   while (u != nullptr && u->row != n) u = u->next_in_col;
    return u;
}

edge_t *find_edge(hungarian_problem_t *p, int row, int col)
{   return find_in_row(p->by_rows[row], col);
}

void hungarian_print_matrix(hungarian_problem_t* p, int rows,
                            int cols)
{   int i,j;
    fprintf(stderr, "\n");
    for(i=0; i<rows; i++)
    {   fprintf(stderr, " [");
        for(j=0; j<cols; j++)
        {   edge_t *e = find_edge(p, i, j);
            fprintf(stderr, "%5d ",e==nullptr ? -1 : e->cost);
        }
        fprintf(stderr, "]\n");
    }
    fprintf(stderr, "\n");
}

void hungarian_print_boolean_matrix(hungarian_problem_t* p, int rows,
                                    int cols)
{   int i,j;
    fprintf(stderr, "\n");
    for(i=0; i<rows; i++)
    {   fprintf(stderr, " [");
        for(j=0; j<cols; j++)
        {   edge_t *e = find_edge(p, i, j);
            fprintf(stderr, "%2d ", e==nullptr ? -1 : e->assigned);
        }
        fprintf(stderr, "]\n");
    }
    fprintf(stderr, "\n");
}

void hungarian_print_assignment(hungarian_problem_t* p)
{   hungarian_print_boolean_matrix(p, p->num_rows, p->num_cols) ;
}

void hungarian_print_costmatrix(hungarian_problem_t* p)
{   hungarian_print_matrix(p, p->num_rows, p->num_cols) ;
}

void hungarian_print_status(hungarian_problem_t* p)
{   fprintf(stderr,"cost:\n");
    hungarian_print_costmatrix(p);
    fprintf(stderr,"assignment:\n");
    hungarian_print_assignment(p);
}

int hungarian_imax(int a, int b)
{   return (a<b)?b:a;
}

int hungarian_init(hungarian_problem_t* p, int rows, int cols,
                   int edges)
{   int i,j, org_cols, org_rows;
    int memsize;
    char *mem;

    org_cols = cols;
    org_rows = rows;

    // is the number of cols  not equal to number of rows ?
    // if yes, expand with 0-cols / 0-cols
    rows = hungarian_imax(cols, rows);
    cols = rows;

    p->num_rows = rows;
    p->num_cols = cols;
#define ROUNDUP(n) (((n) + 7) & ~7)
    memsize = 2*ROUNDUP(rows*sizeof(edge_t *)) +
              ROUNDUP(edges*sizeof(edge_t)) +
              rows*(ROUNDUP(cols*sizeof(int)) + ROUNDUP(cols*sizeof(char)));
    mem = reinterpret_cast<char *>(malloc(memsize));
    hungarian_test_alloc(mem);
    memset(mem, 0, memsize);
    p->memp = 0;

    p->by_rows = (edge_t *)&mem[p->memp];
    p->memp += ROUNDUP(rows+sizeof(edge_t *));
    p->by_cols = (edge_t *)&mem[p->memp];
    p->memp += ROUNDUP(rows+sizeof(edge_t *));
    for(i=0; i<p->num_rows; i++)
    {   p->[i] = reinterpret_cast<int*>()&mem[p->memp];
        p->memp += ROUNDUP(cols*sizeof(int));
        p->assignment[i] = reinterpret_cast<char*>()&mem[p->memp];
        p->memp += ROUNDUP(cols*sizeof(char));
        hungarian_test_alloc(p->assignment[i]);
        for(j=0; j<p->num_cols; j++)
        {   p->cost[i][j] =  (i < org_rows &&
                              j < org_cols) ? cost_matrix[i][j] : 0;
            p->assignment[i][j] = 0;
        }
    }
    return rows;
}

void hungarian_free(hungarian_problem_t* p)
{   int i;
    free(p->cost);
    p->cost = nullptr;
    p->assignment = nullptr;
}

void hungarian_solve(hungarian_problem_t* p)
{   int i, j, m, n, k, l, s, t, q, unmatched, cost;
    int* col_mate;
    int* row_mate;
    int* parent_row;
    int* unchosen_row;
    int* row_dec;
    int* col_inc;
    int* slack;
    int* slack_row;
    char *mem;
    int memsize, memptr = 0;

    cost=0;
    m =p->num_rows;
    n =p->num_cols;

    memsize = 4*ROUNDUP(p->num_rows*sizeof(int)) +
              4*ROUNDUP(p->num_cols*sizeof(int));
    mem = reinterpret_cast<char *>(malloc(memsize));
    hungarian_test_alloc(mem);
    memset(mem, 0, memsize);

    col_mate = reinterpret_cast<int*>()&mem[memptr];
    memptr += ROUNDUP(p->num_rows*sizeof(int));
    unchosen_row = reinterpret_cast<int*>()&mem[memptr];
    memptr += ROUNDUP(p->num_rows*sizeof(int));
    row_dec  = reinterpret_cast<int*>()&mem[memptr];
    memptr += ROUNDUP(p->num_rows*sizeof(int));
    slack_row  = reinterpret_cast<int*>()&mem[memptr];
    memptr += ROUNDUP(p->num_rows*sizeof(int));

    row_mate = reinterpret_cast<int*>()&mem[memptr];
    memptr += ROUNDUP(p->num_cols*sizeof(int));
    parent_row = reinterpret_cast<int*>()&mem[memptr];
    memptr += ROUNDUP(p->num_cols*sizeof(int));
    col_inc = reinterpret_cast<int*>()&mem[memptr];
    memptr += ROUNDUP(p->num_cols*sizeof(int));
    slack = reinterpret_cast<int*>()&mem[memptr];
    memptr += ROUNDUP(p->num_cols*sizeof(int));

    for (i=0; i<p->num_rows; i++)
    {   col_mate[i]=0;
        unchosen_row[i]=0;
        row_dec[i]=0;
        slack_row[i]=0;
    }
    for (j=0; j<p->num_cols; j++)
    {   row_mate[j]=0;
        parent_row[j] = 0;
        col_inc[j]=0;
        slack[j]=0;
    }

    for (i=0; i<p->num_rows; ++i)
        for (j=0; j<p->num_cols; ++j)
            p->assignment[i][j]=HUNGARIAN_NOT_ASSIGNED;

    // Begin subtract column minima in order to start with lots of zeroes 12
    if (verbose)
        fprintf(stderr, "Using heuristic\n");
    for (l=0; l<n; l++)
    {   s=p->cost[0][l];
        for (k=1; k<m; k++)
            if (p->cost[k][l]<s)
                s=p->cost[k][l];
        cost+=s;
        if (s!=0)
            for (k=0; k<m; k++)
                p->cost[k][l]-=s;
    }
    // End subtract column minima in order to start with lots of zeroes 12

    // Begin initial state 16
    t=0;
    for (l=0; l<n; l++)
    {   row_mate[l]= -1;
        parent_row[l]= -1;
        col_inc[l]=0;
        slack[l]=INF;
    }
    for (k=0; k<m; k++)
    {   s=p->cost[k][0];
        for (l=1; l<n; l++)
            if (p->cost[k][l]<s)
                s=p->cost[k][l];
        row_dec[k]=s;
        for (l=0; l<n; l++)
            if (s==p->cost[k][l] && row_mate[l]<0)
            {   col_mate[k]=l;
                row_mate[l]=k;
                if (verbose)
                    fprintf(stderr, "matching col %d==row %d\n",l,k);
                goto row_done;
            }
        col_mate[k]= -1;
        if (verbose)
            fprintf(stderr, "node %d: unmatched row %d\n",t,k);
        unchosen_row[t++]=k;
    row_done:
        ;
    }
    // End initial state 16

    // Begin Hungarian algorithm 18
    if (t==0)
        goto done;
    unmatched=t;
    while (1)
    {   if (verbose)
            fprintf(stderr, "Matched %d rows.\n",m-t);
        q=0;
        while (1)
        {   while (q<t)
            {   // Begin explore node q of the forest 19
                {   k=unchosen_row[q];
                    s=row_dec[k];
                    for (l=0; l<n; l++)
                        if (slack[l])
                        {   int del;
                            del=p->cost[k][l]-s+col_inc[l];
                            if (del<slack[l])
                            {   if (del==0)
                                {   if (row_mate[l]<0)
                                        goto breakthru;
                                    slack[l]=0;
                                    parent_row[l]=k;
                                    if (verbose)
                                        fprintf(stderr, "node %d: row %d==col %d--row %d\n",
                                                t,row_mate[l],l,k);
                                    unchosen_row[t++]=row_mate[l];
                                }
                                else
                                {   slack[l]=del;
                                    slack_row[l]=k;
                                }
                            }
                        }
                }
                // End explore node q of the forest 19
                q++;
            }

            // Begin introduce a new zero into the matrix 21
            s=INF;
            for (l=0; l<n; l++)
                if (slack[l] && slack[l]<s)
                    s=slack[l];
            for (q=0; q<t; q++)
                row_dec[unchosen_row[q]]+=s;
            for (l=0; l<n; l++)
                if (slack[l])
                {   slack[l]-=s;
                    if (slack[l]==0)
                    {   // Begin look at a new zero 22
                        k=slack_row[l];
                        if (verbose)
                            fprintf(stderr,
                                    "Decreasing uncovered elements by %d produces zero at [%d,%d]\n",
                                    s,k,l);
                        if (row_mate[l]<0)
                        {   for (j=l+1; j<n; j++)
                                if (slack[j]==0)
                                    col_inc[j]+=s;
                            goto breakthru;
                        }
                        else
                        {   parent_row[l]=k;
                            if (verbose)
                                fprintf(stderr, "node %d: row %d==col %d--row %d\n",t,row_mate[l],l,
                                        k);
                            unchosen_row[t++]=row_mate[l];
                        }
                        // End look at a new zero 22
                    }
                }
                else
                    col_inc[l]+=s;
            // End introduce a new zero into the matrix 21
        }
    breakthru:
        // Begin update the matching 20
        if (verbose)
            fprintf(stderr, "Breakthrough at node %d of %d!\n",q,t);
        while (1)
        {   j=col_mate[k];
            col_mate[k]=l;
            row_mate[l]=k;
            if (verbose)
                fprintf(stderr, "rematching col %d==row %d\n",l,k);
            if (j<0)
                break;
            k=parent_row[j];
            l=j;
        }
        // End update the matching 20
        if (--unmatched==0)
            goto done;
        // Begin get ready for another stage 17
        t=0;
        for (l=0; l<n; l++)
        {   parent_row[l]= -1;
            slack[l]=INF;
        }
        for (k=0; k<m; k++)
            if (col_mate[k]<0)
            {   if (verbose)
                    fprintf(stderr, "node %d: unmatched row %d\n",t,k);
                unchosen_row[t++]=k;
            }
        // End get ready for another stage 17
    }
done:

    // Begin doublecheck the solution 23
    for (k=0; k<m; k++)
        for (l=0; l<n; l++)
            if (p->cost[k][l]<row_dec[k]-col_inc[l])
            {   printf("Error detected line %d of file %s\n", __LINE__, __FILE__);
                exit(0);
            }
    for (k=0; k<m; k++)
    {   l=col_mate[k];
        if (l<0 || p->cost[k][l]!=row_dec[k]-col_inc[l])
        {   printf("Error detected line %d of file %s\n", __LINE__, __FILE__);
            exit(0);
        }
    }
    k=0;
    for (l=0; l<n; l++)
        if (col_inc[l])
            k++;
    if (k>m)
    {   printf("Error detected line %d of file %s\n", __LINE__, __FILE__);
        exit(0);
    }
    // End doublecheck the solution 23
    // End Hungarian algorithm 18

    for (i=0; i<m; ++i)
    {   p->assignment[i][col_mate[i]]=HUNGARIAN_ASSIGNED;
        //TRACE("%d - %d\n", i, col_mate[i]);
    }
    for (k=0; k<m; ++k)
    {   for (l=0; l<n; ++l)
        {   //TRACE("%d ",p->cost[k][l]-row_dec[k]+col_inc[l]);
            p->cost[k][l]=p->cost[k][l]-row_dec[k]+col_inc[l];
        }
        //TRACE("\n");
    }
    for (i=0; i<m; i++)
        cost+=row_dec[i];
    for (i=0; i<n; i++)
        cost-=col_inc[i];
    if (verbose)
        fprintf(stderr, "Cost is %d\n",cost);

    free(mem);
}

// end of hunsparse.c
