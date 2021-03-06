off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 46000*x1 + 700*x12 + 1500*x5, 3*x10 + 7500000*x11 - 3764475*x2 + 49625*x3 + 20000*x9, 1728*x12 + 174*x2 - 426849*x3 + 300000*x4 + 13000*x5, 187*x11 + 432*x3 - 690985*x4 + 27*x6, 16000*x1 + 2740*x3 - 9630*x5 + 3000*x6, 540000*x4 + 400000*x5 - 150027*x6, 3750000*x10 - 20003*x7 + 125*x9, 10000*x10 + 125*x11 - 7500003*x8, 50000*x12 + 3750000*x2 + 3*x7 - 22150*x9,  - 3760003*x10 + 125*x2 + 20000*x7 + 7500000*x8,  - 7509475*x11 + 10000*x2 + 49250*x4 + 3*x8, 3000000*x1 - 73728*x12 + 150000*x3 + 81*x9};

classifyComponents {basis};

end;
