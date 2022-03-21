%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:SYS-IO.SL
% Description:  UNIX specific IO routines for PSL
% Author:       Russ Fish, Robert R. Kessler, Martin L. Griss              
% Created:      4-May-84                                                   
% Modified:
% Mode:         Lisp                                                       
% Package:                                                                 
% Status:       Experimental (Do Not Distribute)                           
%
% (c) Copyright 1987, University of Utah, all rights reserved.        
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 05-Oct-87 (Harold Carr)
%  Added call to GETUNIXARGS in SYSCLEARIO to make it consistent with VAX.
% 31-Mar-87 (Leigh Stoller)
%  Added calls to setlinebuf back in. This should be in all systems just in
%   line buffering is a problem.
% 15-Feb-85 13:27:04 (Brian Beach)
%  Commented out the setlinebuf calls in syscleario.
% 17-Dec-84 11:14:32 (Vicki O'Day)
%  Uncommented out the setlinebuf calls in syscleario.
% 10-Jul-84 13:30:58 (RAM)
%  Replaced calls to fopen with call to unixopen.  Unixopen will expand
%  shell variables (and some other fancy stuff).
% 21-May-84 (Vicki O'Day)                                                  
%  Added unixcleario call to syscleario.  This is so buffers that are      
%  dirty when a savesystem is done will be cleared.                        
% 4-May-84 11:16:33 (Brian Beach)                                          
%  Added VAXREADCHAR and VAXWRITECHAR to the version received from Utah.   
%  These are needed for RAWIO.                                             
%  Translated from RLISP to LISP.                                          
% Edit by Russ Fish, Wed Dec 21 17:10:07 1983                              
%  Force line buffering on StdOut and StdErr in SysClearIO even if file output.
%                                                                          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Each individual system must have the following routines defined.         
% SysClearIo, SysOpenRead, SysOpenWrite, SysReadRec, SysWriteRec, SysClose,
% SysMaxBuffer                                                             
%                                                                          
%   The following definitions are used in the routines:                    
%    FileDescriptor - A machine dependent word that references a file once 
%                     opened.                                              
%    FileName - A Lisp string of the file name.                            
% FileDescriptors in the Unix version are "FILE *" (pointers to C "standard
% I/O" stream structs, as defined in /usr/include/stdio.h.)                

(compiletime (load io-decls sys-macros))

(fluid '(*bruch* unix-stderr* unix-tty*))

%   C support code in unix-io.c imports knowledge of stdio.h .             
(fluid '(unixeof unixnull unixstderr unixstdout unixstdin unixtty))

% Managed here.                                                            
(de unixstring (s)
  % Strip tags for passing a string.                                       
  (if (stringp s)
    (strbase (strinf s))
    (stderror (bldmsg "Not a string: %p%n" s))))

% Use the C/stdio strlen fn
(de unixstrlen (s)
  % Count chars until null (0) char.                                      
  (external_strlen (unixstring s)))

%------------------------------------------------------------------------------
                                                                           
% Any system dependent clearing that has to be done.                       
(de syscleario ()
  % Establish channels #'s for initial system.                             
  (unixcleario)
  (setf stdin* 0)
  (setf stdout* 1)
  (setf errout* stdout*)
  (setf promptout* stdout*)
  % Hand Build channeltables.                                              
  (clearonechannel stdin* unixstdin
                   'input 'terminalinputhandler)
  % With prompts.                                                          
  (clearonechannel stdout* unixstdout
                   'output 'independentwritechar)
  (setf unix-stderr* 5)
  % As a system-dependent feature /csp                                     
  (clearonechannel unix-stderr* unixstderr
                   'output 'independentwritechar)
  (setf unix-tty* 6)
  % Controlling tty, even when stdin redirected.                           
  (clearonechannel unix-tty* unixtty
                   'input 'terminalinputhandler)
  % With prompts.                                                          

  % Force line buffering on StdOut and StdErr even if file or pipe output. 
  % This only works here on BSD systems. SYSV systems (e.g., HPUX) must
  % have the call in the ukernel.

  (setlinebuf unixstdout)
  (setlinebuf unixstderr) 

% (getunixargs)	
  nil)

%------------------------------------------------------------------------------
                                                                           
% Open FileName for input and return a file descriptor used in later       
% references to the file.                                                  
(de sysopenread (channel filename)
  (prog (filed)
        % Open a Unix StdIO channel.                                       
        (setq filed (unixopen (unixstring filename) (unixstring "r")))
        % unixOpen returns NULL if there is an error.                         
        (return (if (weq filed unixnull)
                  (contopenerror filename 'input)
                  filed))))

%------------------------------------------------------------------------------
                                                                           
% Open FileName for output and return a file descriptor used in later      
% references to the file.                                                  
(de sysopenwrite (channel filename)
  (prog (filed)
        % Open a Unix StdIO channel.                                       
        (setq filed (unixopen (unixstring filename) (unixstring "w")))
        % unixOpen returns NULL if there is an error.                         
        (return (if (weq filed unixnull)
                  (contopenerror filename 'output)
                  filed))))

%------------------------------------------------------------------------------
                                                                           
% Read from the FileDescriptor, putting a line record into the StringBuffer
% terminated by an EOL or EOF character.  Return the length of the string read
% as the indexing bound (one less than the number of characters read.)     

(de sysreadrec (filedescriptor stringbuffer)
    (prog nil
          (setq *bruch* 0)
	  (when (or (weq filedescriptor unixstdin) 
		    (weq filedescriptor unixtty))
		(fflush unixstdout))
	  % Ensure prompts seen before input.                                
	  (cond ((wneq (fgets (unixstring stringbuffer) 
			      (sysmaxbuffer filedescriptor) filedescriptor)
		       unixnull)
		 % Check that not end of file.                             
		 (when (wlessp *bruch* 0) (lisprpv))
		 (return (wdifference (unixstrlen stringbuffer) 1)))
		(t % Index of EOL char.                                       
		   (progn % Return an EOF character on end of file.    
			  (when (wlessp *bruch* 0) (lisprpv))
			  (setf (strbyt (strinf stringbuffer) 0) $eof$)
			  (clearerr filedescriptor)
			  % TTYs can type again after EOF.                   
			  (return 0))))))

    % Index of EOF char.
%----------------------------------------------------------------------------
                                                                           
% Write StringLength+1 characters from StringToWrite from the first position.  
                                                                           
(de syswriterec (filedescriptor stringtowrite stringlength)
  (prog (fw)
    (setq *bruch* 17)
    (setq fw (fwrite (unixstring stringtowrite) (wplus2 stringlength 1) 1
                      filedescriptor))
    (when (wlessp *bruch* 0) % attention happened
          (lisprpv))
    (setq *bruch* 0)
    (return fw)))

%-----------------------------------------------------------------------------
                                                                           
%   Close FileDescriptor, allowing it to be reused.                        
(de sysclose (filedescriptor)
  (fclose filedescriptor))

%-----------------------------------------------------------------------------
                                                                           
%   Return the maximum buffer size.                                        
(de sysmaxbuffer (filedesc)
  200)

%------------------------------------------------------------------------------
                                                                           
(de contopenerror (filename accessmode)
  (continuableerror 99 
                    (bldmsg "`%s' cannot be open for %w" filename 
                     accessmode)
                    (list 'open filename (mkquote accessmode))))

(de vaxreadchar (channel)
  (prog (chr)
        (setq chr (fgetc (wgetv channeltable channel)))
        (when (weq chr -1)
          (setq chr (char eof)))
        (when *echo
          (writechar chr))
        (return chr)))

(de vaxwritechar (channel chr)
  (fputc chr (wgetv channeltable channel)))

