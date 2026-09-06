#include <globaldefs.h>

struct Struct020db0c4 {
    char pad0[0x50];
    unsigned char f50;
    unsigned char f51;
    unsigned char f52;
    unsigned char f53;
    char pad54[0x64 - 0x54];
    unsigned char f64;
    char pad65[0x68 - 0x65];
    short f68;
    short f6a;
};

// USA: func_020db0c4
ARM void InitStruct020db0c4(struct Struct020db0c4* p) {
    p->f68 = -1;
    p->f6a = 0;
    p->f50 = 0;
    p->f52 = 0;
    p->f53 = 1;
    p->f51 = 0;
    p->f64 = 0;
}
