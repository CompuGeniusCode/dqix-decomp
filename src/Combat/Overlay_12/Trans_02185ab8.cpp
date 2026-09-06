#include <globaldefs.h>

extern "C" unsigned int _Z19InitEntries0205d2bcP11Obj0205d2bc(unsigned int);
extern "C" unsigned int _Z29CallInitEntriesIfSet_021e76a8P17Container021e76a8(unsigned int);
extern "C" unsigned int func_ov023_021e6b8c(unsigned int);

// USA: func_ov012_02185ab8  (semantic: Trans_02185ab8)
extern "C" ARM unsigned int func_ov012_02185ab8(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r4 = r0;
    r0 = r4 + 0x128;
    r0 = r0 + 0xc00;
    r0 = (unsigned int)_Z29CallInitEntriesIfSet_021e76a8P17Container021e76a8(r0);
    r0 = r4 + 0x1000;
    r0 = *(unsigned char*)((char*)r0 + 0x371);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { goto L2c; }
    r0 = r4 + 0xac;
    r0 = (unsigned int)_Z19InitEntries0205d2bcP11Obj0205d2bc(r0);
L2c:;
    r0 = r4;
    r0 = (unsigned int)func_ov023_021e6b8c(r0);
    return r0;
}
