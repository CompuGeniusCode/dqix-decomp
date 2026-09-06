#include <globaldefs.h>

// USA: func_ov011_02184324  (semantic: Trans_02184324)
extern "C" ARM unsigned int func_ov011_02184324(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    r2 = *(unsigned int*)((char*)r0 + 0x18);
    cc = (int)(r2) - (int)(0x0);
    if (cc == 0) { goto L28; }
    goto L14;
L10:;
    r2 = r0;
L14:;
    r0 = *(unsigned int*)((char*)r2 + 0x18);
    cc = (int)(r0) - (int)(0x0);
    if (cc != 0) { goto L10; }
    *(unsigned int*)((char*)r2 + 0x18) = (unsigned int)r1;
    return r0;
L28:;
    *(unsigned int*)((char*)r0 + 0x18) = (unsigned int)r1;
    return r0;
    return r0;
}
