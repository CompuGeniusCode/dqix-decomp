#include <globaldefs.h>

struct Shorts5c_374e0 {
    char unk0[0x5c];
    short a;
    short b;
    short c;
};

// USA: func_020374e0
ARM void SetShorts0x5cTo0x60(struct Shorts5c_374e0* obj, short a, short b, short c) {
    obj->a = a;
    obj->b = b;
    obj->c = c;
}
