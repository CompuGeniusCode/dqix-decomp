#include <globaldefs.h>

struct InitState0208f7ecStruct {
    int field0;                     // 0x0
    int field4;                     // 0x4
    char pad8[0xb4 - 8];            // 0x8..0xb3
    unsigned char b4;               // 0xb4
    unsigned char b5;               // 0xb5
    signed char b6;                 // 0xb6
    signed char b7;                 // 0xb7
    signed char b8;                 // 0xb8
    char padb9;                     // 0xb9
    unsigned short ba;              // 0xba
    signed char bc;                 // 0xbc
};

// USA: func_0208f7ec
ARM void InitState0208f7ec(struct InitState0208f7ecStruct* s) {
    s->field0 = 0;
    s->field4 = 0;
    s->b4 = 0;
    s->b5 = 0;
    s->b6 = 1;
    s->b7 = -1;
    s->b8 = -1;
    s->ba = 0;
    s->bc = -1;
}
