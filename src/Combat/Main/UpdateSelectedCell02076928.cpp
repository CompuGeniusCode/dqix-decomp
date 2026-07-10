#include <globaldefs.h>

extern int data_02114e50;

struct Struct02076928 {
    char pad0[0x20];
    int* p20;           // 0x20
    char pad1[0x30];    // 0x24..0x53
    int f54;            // 0x54
    char pad2[0x7];     // 0x58..0x5e
    unsigned char f5f;  // 0x5f
    int f60;            // 0x60
    int f64;            // 0x64
    int f68;            // 0x68
    int f6c;            // 0x6c
};

// USA: func_02076928
ARM void UpdateSelectedCell02076928(struct Struct02076928* s, int val) {
    int* base;
    if (s->f5f == 0) return;
    if (s->f54 <= 0) return;
    if (s->f64 == val || val == 0) return;
    s->f60 = 0;
    s->f64 = val;
    s->f68 = data_02114e50;
    base = s->p20;
    s->f6c = ((int*)base[s->f64])[s->f60];
}
