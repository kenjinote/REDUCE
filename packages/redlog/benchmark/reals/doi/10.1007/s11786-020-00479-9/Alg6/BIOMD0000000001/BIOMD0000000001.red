off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{1965978958518314488929181915123221008*x1-3920232604625330275850839793764372901*x3, 737242109444367933348443218171207878*x10-345884337533865649523206626016869336875*x3, 230388159201364979171388505678502461875*x11-3458886300238998539080855410980485901*x3, 491494739629578622232295478780805252*x12-42018616422917857740319420874743990625*x3, 245747369814789311116147739390402626*x2-2767116656060921843195034969223618695*x3, 1151940796006824895856942528392512309375*x4-3276060253217441218750379501496483571*x3, 122873684907394655558073869695201313*x5-2611607242858132959010177169328249154*x3, 1843105273610919833371108045428019695*x6-104464356237261143815940219719509074272*x3, 122873684907394655558073869695201313*x7-10808885547802046620916778190108695312500*x3, 5529315820832759500113324136284059085*x8-3458843375355826448500902492149860901*x3, 122873684907394655558073869695201313*x9-259413232146460849553383009607174312500*x3}};

classifyComponents P;

end;