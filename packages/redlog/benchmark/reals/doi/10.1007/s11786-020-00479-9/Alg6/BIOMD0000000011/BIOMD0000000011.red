off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x10, x12, x13, x14, x15, x16, x17, x19, x2, x21, x22, x4, x5, x6, x8}, {x10, x12, x13, x14, x15, x16, x18, x19, x2, x21, x22, x4, x5, x6, x8}, {x10, x12, x13, x14, x15, x16, x2, x4, x5, x6, x8, x9, x22-x21, 2*x17*x18-x21, 5*x19*x20-6*x21}, {x11, x12, x13, x14, x15, x16, x17, x19, x2, x21, x22, x4, x5, x6, x8}, {x11, x12, x13, x14, x15, x16, x18, x19, x2, x21, x22, x4, x5, x6, x8}, {x10, x12, x13, x14, x15, x16, x17, x19, x2, x21, x22, x3, x5, x6, x7, x8}, {x10, x12, x13, x14, x15, x16, x17, x2, x20, x21, x22, x4, x5, x6, x8, x9}, {x10, x12, x13, x14, x15, x16, x18, x19, x2, x21, x22, x3, x5, x6, x7, x8}, {x10, x12, x13, x14, x15, x16, x18, x2, x20, x21, x22, x4, x5, x6, x8, x9}, {x10, x12, x13, x14, x15, x16, x2, x3, x5, x6, x7, x8, x9, x22-x21, 2*x17*x18-x21, 5*x19*x20-6*x21}, {x10, x12, x13, x14, x15, x16, x17, x2, x20, x21, x22, x3, x5, x6, x7, x8, x9}, {x10, x12, x13, x14, x15, x16, x18, x2, x20, x21, x22, x3, x5, x6, x7, x8, x9}, {x11, x12, x14, x15, x16, x17, x19, x21, x22, x5-x2, x8-x6, 200*x1*x13-7*x2, x1*x7-x3^2, 200*x13*x3-7*x6, 10*x3*x4-x2, 10*x4*x7-x6, x1*x6-x2*x3, -20*x13*x2+7*x4*x6, x2*x7-x3*x6}, {x11, x12, x14, x15, x16, x18, x19, x21, x22, x5-x2, x8-x6, 200*x1*x13-7*x2, x1*x7-x3^2, 200*x13*x3-7*x6, 10*x3*x4-x2, 10*x4*x7-x6, x1*x6-x2*x3, -20*x13*x2+7*x4*x6, x2*x7-x3*x6}, {x10, x11, x12, x14, x15, x16, x9, x22-x21, x5-x2, x8-x6, 200*x1*x13-7*x2, x1*x7-x3^2, 200*x13*x3-7*x6, 2*x17*x18-x21, 5*x19*x20-6*x21, 10*x3*x4-x2, 10*x4*x7-x6, x1*x6-x2*x3, -20*x13*x2+7*x4*x6, x2*x7-x3*x6}, {x10, x11, x12, x14, x15, x16, x17, x20, x21, x22, x9, x5-x2, x8-x6, 200*x1*x13-7*x2, x1*x7-x3^2, 200*x13*x3-7*x6, 10*x3*x4-x2, 10*x4*x7-x6, x1*x6-x2*x3, -20*x13*x2+7*x4*x6, x2*x7-x3*x6}, {x10, x11, x12, x14, x15, x16, x18, x20, x21, x22, x9, x5-x2, x8-x6, 200*x1*x13-7*x2, x1*x7-x3^2, 200*x13*x3-7*x6, 10*x3*x4-x2, 10*x4*x7-x6, x1*x6-x2*x3, -20*x13*x2+7*x4*x6, x2*x7-x3*x6}, {x17, x20, x21, x22, x15-x14, x16-x12, x5-x2, x8-x6, 200*x1*x13-7*x2, x1*x7-x3^2, 100*x10*x11-9*x12, -26*x10^2+25*x13*x9, 33*x10*x19-5*x14, 100*x11*x13-9*x14, 165*x19*x9-26*x12, 200*x13*x3-7*x6, 10*x3*x4-x2, 10*x4*x7-x6, 208*x1*x10^2-7*x2*x9, 18*x1*x14-7*x11*x2, x1*x6-x2*x3, -x10*x14+x12*x13, -26*x10*x12+25*x14*x9, 208*x10^2*x3-7*x6*x9, -500*x11*x14+297*x12*x19, 7*x11*x6-18*x14*x3, -20*x13*x2+7*x4*x6, x2*x7-x3*x6, 200*x10*x14*x3-7*x12*x6, -468*x1*x10*x12+175*x11*x2*x9}, {x18, x20, x21, x22, x15-x14, x16-x12, x5-x2, x8-x6, 200*x1*x13-7*x2, x1*x7-x3^2, 100*x10*x11-9*x12, -26*x10^2+25*x13*x9, 33*x10*x19-5*x14, 100*x11*x13-9*x14, 165*x19*x9-26*x12, 200*x13*x3-7*x6, 10*x3*x4-x2, 10*x4*x7-x6, 208*x1*x10^2-7*x2*x9, 18*x1*x14-7*x11*x2, x1*x6-x2*x3, -x10*x14+x12*x13, -26*x10*x12+25*x14*x9, 208*x10^2*x3-7*x6*x9, -500*x11*x14+297*x12*x19, 7*x11*x6-18*x14*x3, -20*x13*x2+7*x4*x6, x2*x7-x3*x6, 200*x10*x14*x3-7*x12*x6, -468*x1*x10*x12+175*x11*x2*x9}, {x15-x14, x16-x12, x22-x21, x5-x2, x8-x6, 200*x1*x13-7*x2, x1*x7-x3^2, 100*x10*x11-9*x12, -26*x10^2+25*x13*x9, 33*x10*x19-5*x14, 100*x11*x13-9*x14, 165*x19*x9-26*x12, 200*x13*x3-7*x6, 2*x17*x18-x21, 5*x19*x20-6*x21, 10*x3*x4-x2, 10*x4*x7-x6, 208*x1*x10^2-7*x2*x9, 18*x1*x14-7*x11*x2, x1*x6-x2*x3, -x10*x14+x12*x13, -26*x10*x12+25*x14*x9, -198*x10*x21+25*x14*x20, 208*x10^2*x3-7*x6*x9, -500*x11*x14+297*x12*x19, 7*x11*x6-18*x14*x3, 13*x12*x20-99*x21*x9, -20*x13*x2+7*x4*x6, x2*x7-x3*x6, 200*x10*x14*x3-7*x12*x6, -468*x1*x10*x12+175*x11*x2*x9, -3564*x1*x10*x21+175*x11*x2*x20}};

classifyComponents P;

end;