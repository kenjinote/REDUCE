off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 3*x1*x2,  - 3*x1*x2, 3*x1*x2 - 20000000000000*x3*x4 + 200000000000*x9, 100*x11 - 10000000*x3*x4 - 100000*x4 + x5**2 + 100000*x9, 100000*x4 - x5**2, 40000*x10 - x6*x8, 40000*x10 + x6*x8 - 140400*x7*x9, 3*x12 - 10000000000000*x18*x8 + 160000*x19 + 1500000*x22 - 25*x6*x8, 100*x10 + 1000000000*x3*x4 - 351*x7*x9 - 10000000*x9,  - 200*x10 + 351*x7*x9, x10 - 100*x11, 100000000*x11 - 500*x12*x13 - 3*x12 + 500000*x14,  - 2*x12*x13 - 2*x13*x19 + 2000*x14 + 3*x17 + 2000*x21, 50000*x12*x13 - 780000000*x14*x15 - 50000000*x14 + x16,  - 780000000*x14*x15 - 780000000*x15*x17 + x16 + 1000000000000000*x18*x8 + x20, 780000000*x14*x15 - 500000001*x16, 50000*x13*x19 - 780000000*x15*x17 + 500000000*x16 - 75000*x17 + x20, 10*x16 - 20000000*x18*x8 + x20,  - 2*x13*x19 + 3*x17 - 320*x19, 780000000*x15*x17 - 50000001*x20, x20 - x21, x21 - x22, 3*x12 + 80000*x19 + 500000*x22};

classifyComponents {basis};

end;
