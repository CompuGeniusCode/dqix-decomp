#include <globaldefs.h>

struct Source0203c05c {
    char pad[0x22];
    short f22;
};

struct Entry0203c05c {
    unsigned int w;
    unsigned short h;
    unsigned short pad;
};

// USA: func_0203c05c
ARM void BuildPackedEntries0203c05c(struct Source0203c05c* p, struct Entry0203c05c* out,
                                    int a3, int a4, int a5, int a6) {
    short v = p->f22;
    int i;
    if (v < 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        out->w = 0x80000000 | 0x4000 | (a5 & 0xff) | ((a4 & 0x1ff) << 16);
        out->h = (unsigned short)(v | ((a3 & 3) << 10) | ((a6 & 0xf) << 12));
        out++;
        a4 += 0x20;
        v = (short)(v + 2);
    }
}
