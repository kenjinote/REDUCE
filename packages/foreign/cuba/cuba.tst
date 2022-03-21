% cuba.tst                                           Kostas N. Oikonomou

load_package assist, cuba;

% All integrals are evaluated over hyper-rectangles.

procedure f1(x);
   sin(x.1) * cos(x.2) * exp(x.3);

procedure f2(x);
   1/((x.1 + x.2)^2 + 0.003) * cos(x.2) * exp(x.3);

procedure f3(x);
   1/(3.75 - for each xi in x sum cos(pi*xi));

procedure f4(x);
   abs(for each xi in x sum xi^2 - 0.125);

procedure f5(x);
   exp(- for each xi in x sum xi^2);

procedure f6(x);
   1/(1 - for each xi in x product xi + 1e-10);

procedure f7(x);
   sqrt(abs(x.1) - x.2 - x.3);

procedure f8(x);
   exp(- for each xi in x product xi);
   
procedure f9(x);
   begin scalar s;
      s := for each xi in x sum xi;
      return (x.1)^2/(cos(s+1) + 5);
   end;

% Discontinuous function
procedure f10(x);
   begin scalar p;
      p := for each xi in x product xi;
      return if x.1 > 0.5 then 1/sqrt(p + 1e-5) else sqrt(p);
   end;

% Indicator function for the unit hypersphere.
% As the number of dimensions increases, the ratio of the volume of the unit 
% hypersphere to the volume of the unit hypercube tends to 0!
procedure unit_sphere(x);
   begin scalar s;
      s := for each xi in x sum xi^2;
      return if s < 1 then 1.0 else 0.0;
   end;


%% ============================================================================
%% A lot of effort has gone into making the package work even if we are not
%% in rounded mode. Still, we're doing numerical integration, so having it on
%% can't hurt, and might avoid problems that haven't been discovered yet.
on rounded;
%% ============================================================================


%% Change some parameters applicable to all algorithms
%cuba_gen_par("maxeval", 80);
%cuba_gen_par("epsrel", 0.001);
%cuba_gen_par("epsabs", 1e-12);

%% Set some Vegas-specific parameters
%cuba_vegas_par("nstart", 10);
%cuba_vegas_par("nincrease", 5);
%cuba_vegas_par("nbatch", 80);

%% And some Suave-specific parameters
%cuba_suave_par("nnew", 1000);
%cuba_suave_par("flatness", 25);


% Verbosity. Level 0 does not print any output, level 1 prints reasonable
% information on the progress of the integration, level 2 also echoes the input
% parameters, and level 3 further prints the subregion results, when applicable.
cuba_verbosity(0);

% See the Cuba manual for what this does:
cuba_set_flags_bit("Suave",2);
cuba_set_flags_bit("Cuhre",2);

%% Run the algorithms on the 10 test functions R^3 -> R.
for each f in {f1,f2,f3,f4,f5,f6,f7,f8,f9,f10} do
<<
   write "=== Integrand ", f;
   if f eq f2 or f eq f7 then
      write f, " takes a while, you may want to do this by hand"
   else
      for each alg in cuba_algorithms do <<
      	 write "Algorithm ", alg, ":";
      	 write cuba_int(f,{{0,1},{0,1},{0,1}},alg);   
      >>;
>>;

%% Exact value for f1 is 0.664669679781

%% Unit spheres are a difficult test case as the dimension goes up.
%% The volume of n-dim sphere with radius 1/2 is
%%   for n := 1:4 collect 2 * pi^(n/2)/gamma(n/2) * (1/2)^n/n;
%% write "1d unit sphere: answer should be 1.0";
%% cuba_int(unit_sphere,{{0,1}},Vegas);
%% write "2d unit sphere: answer should be 0.785398163397";
%% cuba_int(unit_sphere,{{0,1},{0,1}},Vegas);
%% write "3d unit sphere: answer should be 0.523598775598";
%% cuba_int(unit_sphere,{{0,1},{0,1},{0,1}},Divonne);
%% cuba_int(unit_sphere,{{0,1},{0,1},{0,1}},Cuhre);
% Divonne does much better than others in 4d, but still, its answer 
% doesn't meet epsrel = 0.001:
%% write "4d unit sphere: answer should be 0.308425137534";
%% cuba_int(unit_sphere,{{0,1},{0,1},{0,1},{0,1}},Suave);
%% cuba_int(unit_sphere,{{0,1},{0,1},{0,1},{0,1}},Divonne);


end;
