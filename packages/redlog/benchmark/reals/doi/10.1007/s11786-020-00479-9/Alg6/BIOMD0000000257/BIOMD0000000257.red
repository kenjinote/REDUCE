off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x10, x11, x4, x5, x6, x7, x8, x9}, {90156250*x4^4+543021875*x4^3-6511854000*x4^2+18368100*x4+940131522, 279812543750*x4^3-1688675565500*x4^2+22404320250*x10-91954595925*x4+243180687024, 139906271875*x4^3-844337782750*x4^2+11202160125*x11-42616649925*x4+121590343512, -5409375*x4^3-2744156750*x4^2-11555384850*x4+7468106750*x5-5012994096, -1496593750*x4^3-41033768375*x4^2-29018925150*x4+44808640500*x6-91600186986, 69945021875*x4^3-426285126500*x4^2-21838162050*x4+11202160125*x7+53275680612, -1399225000*x4^3+8361053125*x4^2-256559850*x4+1344259215*x8-1366293258, 1431681250*x4^3+8103887375*x4^2-108301433835*x4+1344259215*x9+31444257834}};

classifyComponents P;

end;
