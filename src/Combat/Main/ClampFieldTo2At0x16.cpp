#include <globaldefs.h>

struct Clamp020e29a8 {
    char pad[0x16];
    unsigned char v;
};

// USA: func_020e29a8
ARM void ClampFieldTo2At0x16(struct Clamp020e29a8* p, int v) {
    if (v >= 3) {
        v = 2;
    }
    p->v = (unsigned char)v;
}
