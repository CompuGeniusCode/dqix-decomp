#include <globaldefs.h>

struct Pack020e197c {
    unsigned int w;
    unsigned short h;
};

// USA: func_020e197c
ARM void PackControlWord020e197c(struct Pack020e197c* d, int a2, int a3, int a4,
        int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12) {
    if (a7 == 0x100 || a7 == 0x300) {
        if (a5 == 3) {
            d->w = (a3 & 0xff) | (a12 << 25) | (a5 << 10) | (a6 << 12) | a8 | ((a2 & 0x1ff) << 16) | a7;
        } else {
            d->w = (a3 & 0xff) | ((a12 << 25) | (a9 << 13)) | (a5 << 10) | (a6 << 12) | a8 | ((a2 & 0x1ff) << 16) | a7;
        }
    } else {
        if (a5 == 3) {
            d->w = (a3 & 0xff) | (a5 << 10) | (a6 << 12) | a8 | ((a2 & 0x1ff) << 16) | a7;
        } else {
            d->w = (a3 & 0xff) | (a9 << 13) | (a5 << 10) | (a6 << 12) | a8 | ((a2 & 0x1ff) << 16) | a7;
        }
    }
    d->h = (unsigned short)(a10 | (a4 << 10) | (a11 << 12));
}
