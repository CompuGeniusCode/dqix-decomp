#include <globaldefs.h>

struct Obj0207b108 {
    char pad0[0x11];
    unsigned char field0x11;
    unsigned char field0x12;
    unsigned char field0x13;
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0207b108
extern "C" ARM int _Z26ScaleByteToPercent0207b108P11Obj0207b108(struct Obj0207b108* obj) {
    unsigned int val = (unsigned int)(90.0f * ((float)obj->field0x13 / 31.0f));
    obj->field0x12 = (unsigned char)val;
    if ((val & 0xff) != 0) {
        val = (obj->field0x11 | 4) & ~2;
        obj->field0x11 = val;
    }
    return val;
}
