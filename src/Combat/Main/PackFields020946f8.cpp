#include <globaldefs.h>

struct PackFields020946f8Struct { unsigned int w; unsigned short h; };

// USA: func_020946f8
ARM void PackFields020946f8(struct PackFields020946f8Struct* dst, int p1, int p2, int p3,
                            int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12) {
    if (a7 == 0x100 || a7 == 0x300) {
        if (a5 == 3) {
            dst->w = (p2 & 0xff) | (a12 << 0x19) | (a5 << 0xa) | (a6 << 0xc) | a8 | ((p1 & 0x1ff) << 0x10) | a7;
        } else {
            dst->w = (p2 & 0xff) | ((a12 << 0x19) | (a9 << 0xd)) | (a5 << 0xa) | (a6 << 0xc) | a8 | ((p1 & 0x1ff) << 0x10) | a7;
        }
    } else {
        if (a5 == 3) {
            dst->w = (p2 & 0xff) | (a5 << 0xa) | (a6 << 0xc) | a8 | ((p1 & 0x1ff) << 0x10) | a7;
        } else {
            dst->w = (p2 & 0xff) | (a9 << 0xd) | (a5 << 0xa) | (a6 << 0xc) | a8 | ((p1 & 0x1ff) << 0x10) | a7;
        }
    }
    dst->h = a10 | (p3 << 0xa) | (a11 << 0xc);
}
