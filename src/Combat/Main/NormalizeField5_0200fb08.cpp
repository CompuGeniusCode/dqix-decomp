#include <globaldefs.h>

extern "C" void func_020c99c8(void* out);

struct Struct0200fb08 { unsigned char pad[5]; unsigned char field5; };

// USA: func_0200fb08
ARM unsigned char NormalizeField5_0200fb08(Struct0200fb08* obj) {
    unsigned char buf[0x54];
    unsigned char v;
    func_020c99c8(buf);
    v = buf[0];
    obj->field5 = v;
    if (v != 2 && v != 5) obj->field5 = 1;
    return obj->field5;
}
