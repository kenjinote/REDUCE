off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 5000000*x1*x10 + 10*x2, 50000000*x1*x10 - 1000000000*x2*x4 - 100*x2 + x3 + 10*x7, 1000000000*x2*x4 - 51*x3 + 1000000*x5*x6,  - 1000000000*x2*x4 + x3 + 20*x9, 5*x3 - 100000*x5*x6 - 5000000*x5*x8 + 55*x7, 5*x3 - 100000*x5*x6, 5000000*x5*x8 - 56*x7,  - 5000000*x5*x8 + 55*x7, x7 - 2*x9,  - 5000000*x1*x10 + 10*x2};

classifyComponents {basis};

end;
