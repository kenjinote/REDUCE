depend r,x;

depend {u}, a, b, {a, b}, v;

df(u,v);

on expanddf;

df(u,v);

operator f;

df(f(a),v);

df(f(u),v);

let x^3=u;

let f(r)^3=u;

df(x,u);

df (f(r),u);

df(f(r,r^2),x);

df(f(r,cos(x)),x);

df(f(r,cos y),x);

depend cos(y),x;

df(f(r,cos y),x);

depend y,x;

df(f(r,cos y),x);

df(cos y,x);

nodepend y,x;

df(cos y,x);

off expanddf;

df(f(r),r,x);

on expanddf;

df(f(r),r,x);

operator g;

off expanddf;

depend g(v),a1;

df(g(v),a1);

on expanddf;

df(g(v),a1);

off expanddf;

df(df(int(g(v),v),a1),v);

on expanddf;

df(df(int(g(v),v),a1),v);

% more chain rule tests: multiple derivatives

off expanddf;
operator y;
depend ux,x;

COMMENT
 Since ux depends on x, derivatives w.r.t. x can be expressed via
 the chain through derivatives w.r.t. uxi, if the switch expanddf
 is set to on ;

df(y(x),x);

df(y(ux),x);

df(y(x),x,ux);

df(y(x),ux,x);

df(y(ux),x,ux);

df(y(ux),ux,x);

on expanddf;

df(y(x),x);

df(y(ux),x);

df(y(x),x,ux);

df(y(x),ux,x);

df(y(ux),x,ux);

df(y(ux),ux,x);

off expanddf;

COMMENT 
 Now do the same, but with an explicit value for the derivative of ux w.r.t. x;

let df(ux,x) = 1/e**x;

df(y(x),x);

df(y(ux),x);

df(y(x),x,ux);

df(y(x),ux,x);

df(y(ux),x,ux);

df(y(ux),ux,x);

on expanddf;

df(y(x),x);

df(y(ux),x);

df(y(x),x,ux);

df(y(x),ux,x);

df(y(ux),x,ux);

df(y(ux),ux,x);

% test commuting vs. non-commuting

off expanddf;

df(df(g(v),a1),v);

on expanddf;

df(df(g(v),a1),v);

on commutedf;

df(df(g(v),a1),v);

off commutedf;

df(df(g(v),a1),v);

depend uuu,xxx;

off expanddf;

df(uuu,xxx,uuu);

df(y(uuu),xxx,uuu);

df(y(uuu),uuu,xxx);

on commutedf;

df(uuu,xxx,uuu);

df(y(uuu),xxx,uuu);

df(y(uuu),uuu,xxx);

off commutedf;
on expanddf;

df(uuu,xxx,uuu);

df(y(uuu),xxx,uuu);

df(y(uuu),uuu,xxx);

on commutedf;

df(uuu,xxx,uuu);

df(y(uuu),xxx,uuu);

df(y(uuu),uuu,xxx);


% test inconsistent dependencies

operator h;

depend u1,a2,b1;

depend {a2,b1,c1},v1;

depend h(u1),a2,b1,c1;

off expanddf;

df(h(u1),v1);

on expanddf;

df(u1,v1);

df(h(u1),v1);


df(f(g(u),h(u)),u);

% test for odesolve
symbolic (!*df_partial := t);
df(f(g(u),h(u)),u);
symbolic (!*df_partial := nil);


on allowdfint;

depend xx,vv;

df(int(exp(vv*xx^3)/xx,xx),vv);

% test differentiation of parameter integral;

df(int(f(vv,xx),xx),vv);

on allowdfint,dfint;

% this used to return int(df(f(vv,xx),vv),xx)
% which is wrong since xx, the upper limit of the integration depends on vv
df(int(f(vv,xx),xx),vv);

end;
