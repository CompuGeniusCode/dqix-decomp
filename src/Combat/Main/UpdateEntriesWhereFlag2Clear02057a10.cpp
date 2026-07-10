#include <globaldefs.h>

extern "C" void func_02059f54(void* elem, int idx);

struct Elem02057a10 {
    char pad0[0xb2];
    short flag;                 // 0xb2
    char pad1[0x18];            // 0xb4..0xcb
    unsigned char b0 : 1;       // 0xcc bit0
    unsigned char b1 : 1;       // bit1 (0x2)
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    char pad2[7];               // 0xcd..0xd3
};

struct Container02057a10 {
    char hdr[8];
    struct Elem02057a10 elems[16];
};

// USA: func_02057a10
ARM void UpdateEntriesWhereFlag2Clear02057a10(struct Container02057a10* c) {
    int i;
    for (i = 0; i < 16; i++) {
        if (!c->elems[i].b1 && c->elems[i].flag <= -1) {
            func_02059f54(&c->elems[i], i + 0xd0);
        }
    }
}
