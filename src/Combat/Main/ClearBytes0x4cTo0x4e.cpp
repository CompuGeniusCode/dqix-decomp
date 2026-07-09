#include <globaldefs.h>

struct Struct_0205bc10 {
    char unk0[0x4c];
    unsigned char b4c;
    unsigned char b4d;
    unsigned char b4e;
};

// USA: func_0205bc10
ARM void ClearBytes0x4cTo0x4e(struct Struct_0205bc10* s) {
    s->b4c = 0;
    s->b4d = 0;
    s->b4e = 0;
}
