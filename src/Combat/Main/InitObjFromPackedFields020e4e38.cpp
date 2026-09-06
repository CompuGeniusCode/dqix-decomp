#include <globaldefs.h>
#include "std_library_functions.h"

struct PackedFields020e4e38 {
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 6;
    unsigned int d : 6;
    unsigned int e : 2;
    unsigned int f : 1;
    unsigned int g : 1;
    unsigned int h : 1;
    unsigned int pad : 3;
};

struct Src020e4e38 {
    void* field0x0;
    char pad1[0x30];
    void* field0x34;
    struct PackedFields020e4e38 packed;
};

extern "C" void func_020e4b34(void* obj, void* stats1, void* stats2,
    int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12);

// USA: func_020e4e38
ARM void InitObjFromPackedFields020e4e38(void* obj, struct Src020e4e38* src) {
    memset(obj, 0, 0xc);
    if (src != NULL) {
        func_020e4b34(obj, src->field0x0, src->field0x34,
            (unsigned char)src->packed.a, (unsigned char)src->packed.b,
            (unsigned char)src->packed.c, (unsigned char)src->packed.d,
            (unsigned char)src->packed.e, (unsigned char)src->packed.f,
            (unsigned char)src->packed.g, (unsigned char)src->packed.h, 0);
    }
}
