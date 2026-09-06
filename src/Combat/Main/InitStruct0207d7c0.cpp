#include <globaldefs.h>

struct Init0207d7c0 {
    short h0;
    unsigned short h2;
    char b4;
    char b5;
    char pad6[2];
    char b8;
    char b9;
    char ba;
    char bb;
};

// USA: func_0207d7c0
ARM void InitStruct0207d7c0(struct Init0207d7c0* o) {
    o->h0 = 0;
    o->b4 = -1;
    o->b8 = -1;
    o->b9 = -1;
    o->ba = -1;
    o->bb = -1;
    o->h2 = 0x75a4;
    o->b5 = 0;
}
