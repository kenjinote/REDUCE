off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 43*x1*x74 + 1000000*x2, 43*x1*x74 - 100000*x2*x44 - 1000000*x2 + 100000000*x51,  - 683*x3*x59 - 50000*x3*x74 + 47500000*x4,  - 200*x14*x4 + x3*x74 - 200*x4*x44 - 200*x4*x6 - 950*x4 + 132000*x52 + 15950*x67 + 29400*x68,  - x5*x74 + 290*x6,  - 200*x24*x6 - 200*x4*x6 + 2000*x46 - 200*x48*x6 + 13880*x49 + x5*x74 - 290*x6 + 13880*x67,  - 57*x7*x74 + 17000*x8,  - 100000*x24*x8 + 100000*x44 + 4300*x46 + 23000*x49 - 10000*x56*x8 + 160000*x63 + 103500*x67 + 57*x7*x74 - 17000*x8, 1320*x10 - x74*x9,  - 100*x10*x24 - 10*x10*x35 - 1320*x10 + 10*x37 + 89600*x66 + x74*x9,  - x11*x74 + 454*x12, x11*x74 - 1000*x12*x35 - 454*x12 + 10*x36 + 30400*x66,  - x13*x74 + 200*x14, x13*x74 - 200*x14*x24 - 200*x14*x4 - 200*x14*x48 - 200*x14 + 4200*x47 + 27600*x50 + 27600*x68,  - x15*x74 + 670*x16, x15*x74 - 200*x16*x20 - 200*x16*x56 - 670*x16 + 400*x43 + 46*x47 + 1800*x50 + 3200*x57 + 1800*x68,  - x17*x74 + 230*x18, x17*x74 - 20*x18*x36 - 20*x18*x55 - 230*x18 + 4180*x38 + 2834*x73,  - 49*x19*x59 - 50000*x19*x74 + 11500000*x20,  - 200*x16*x20 + x19*x74 - 230*x20 + 680*x38 + 400*x43 + 366*x73,  - x21*x74 + 19000*x22, x21*x74 - 1000*x22*x36 - 1000*x22*x43 - 19000*x22 + 325000*x40 + 107000*x45,  - 160000*x23*x58 - 23*x23*x59 - 2900*x23*x74 - 14*x23*x75 + 33000000*x24 + 3300*x61,  - 5000*x10*x24 - 10000*x14*x24 + 29*x23*x74 - 5000*x24*x37 - 10000*x24*x6 - 100000*x24*x8 - 330000*x24 + 100000*x41 + 6000000*x42 + 100000*x44 + 830000*x45 + 104300*x46 + 212300*x47 + 6000000*x66,  - x25*x74 + 7000*x26, x25*x74 - 200*x26*x28 - 7000*x26 + 1000*x56 + 7200*x71,  - x27*x74 + 400*x28,  - 200*x26*x28 + x27*x74 - 400*x28 + 1000*x56,  - x29*x74 + 670*x30, x29*x74 - 670*x30 + 800*x57,  - 57*x31*x74 + 17000*x32, 57*x31*x74 - 17000*x32 + 40000*x63,  - x33*x74 + 23000*x34, x33*x74 - 200*x34*x70 - 23000*x34 + 12800*x71,  - x10*x35 - 100*x12*x35 + x36 + x37, 5000*x12*x35 - 100*x18*x36 - 1000*x22*x36 - 100*x36*x61 - 50*x36 + 24300*x38 + 325000*x40 + 10000*x41 + 152000*x42 + 11*x62, x10*x35 - 10*x24*x37 - x37 + 8960*x42, x18*x36 - 243*x38, 0, x22*x36 - 340*x40, 3*x40 - 2*x41, x24*x37 - 1200*x42, x16*x20 - x22*x43 - 2*x43 + 190*x45,  - x2*x44 + 10*x24*x8 - x4*x44 - 10*x44 + 1000*x51 + 810*x52, x22*x43 - 190*x45, 100*x24*x6 - 1043*x46, 100*x14*x24 - 2123*x47,  - 10000000*x14*x48 - 10000000*x48*x53 - 683*x48*x59 - 10000000*x48*x6 - 100000000*x48*x69 - 250*x48*x75 + 717000000*x49 + 1470000000*x50 + 1500000000*x52 + 1143000000*x54 + 50000000*x70, 10*x48*x6 - 717*x49, x14*x48 - 147*x50, x2*x44 - 1130*x51, x4*x44 + 130*x51 - 810*x52,  - x48*x53 + 100*x54, 10*x48*x53 - 1143*x54,  - 100000*x18*x55 + 14300000*x54 - 23*x55*x59 + 16000000*x73,  - x16*x56 + x26*x28 - x56*x8 - 5*x56 + 20*x57 + 20*x63, x16*x56 - 20*x57,  - 1600*x23*x58 + 33*x61,  - 49*x19*x59 - 230*x23*x59 - 683*x3*x59 - 683*x48*x59 - 230*x55*x59, 683*x48*x59, 1600*x23*x58 - 1000*x36*x61 - 33*x61 + 110*x62, 100*x36*x61 - 11*x62, x56*x8 - 20*x63, 49*x19*x59, 23*x23*x59, x10*x24 - 1200*x66, 4*x4*x6 - 319*x67, x14*x4 - 147*x68,  - 2*x48*x69 + x70,  - x34*x70 + 10*x48*x69 - 5*x70 + 100*x71, x34*x70 - 100*x71, 683*x3*x59, x18*x55 - 160*x73,  - 43*x1*x74 + 660000*x10 - 500*x11*x74 + 227000*x12 - 500*x13*x74 + 100000*x14 - 500*x15*x74 + 335000*x16 - 500*x17*x74 + 115000*x18 - 500*x19*x74 + 1000000*x2 + 115000*x20 - 100*x21*x74 + 1900000*x22 - 290*x23*x74 + 3300000*x24 - 500*x25*x74 + 3500000*x26 - 500*x27*x74 + 200000*x28 - 500*x29*x74 - 500*x3*x74 + 335000*x30 - 570*x31*x74 + 170000*x32 - 500*x33*x74 + 11500000*x34 + 475000*x4 - 500*x5*x74 + 15000000*x52 + 145000*x6 - 570*x7*x74 - 500*x74*x9 + 170000*x8,  - 14*x23*x75 - 25*x48*x75, x48*x75, 7*x23*x75, 23*x55*x59};

classifyComponents {basis};

end;
