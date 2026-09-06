#include <globaldefs.h>
#pragma optimize_for_size off

ARM void TestGotoOptSize_regtest12(unsigned short val, char* dst, int n) {
    int i = 0;
L_test:
    if (i < n) goto L_store; else goto L_end;
L_store:
    *(unsigned short*)(dst + i) = val;
    if (i < n) goto L_inc; else goto L_end;
L_inc:
    i += 2;
    if (i < n) goto L_test;
L_end:
    return;
}
