#include <globaldefs.h>

struct Elem_0205d81c {
    char pad0[0xC4];
    unsigned char fieldC4;
    char pad1[0xE0 - 0xC5];
};

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205d81c* field9C;
    char pad1[0xB3 - 0xA0];
    unsigned char fieldB3;
    unsigned char fieldB4;
};

// USA: func_0205d81c
ARM struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key) {
    unsigned char i;
    if (s->field98 == 0) return 0;
    if (s->field9C == 0) return 0;
    for (i = 0; i < s->fieldB3; i++) {
        if (i == s->fieldB4) break;
        if (key == s->field9C[i].fieldC4) return &s->field9C[i];
    }
    return 0;
}
