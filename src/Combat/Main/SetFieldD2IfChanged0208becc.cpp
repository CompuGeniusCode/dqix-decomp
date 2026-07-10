#include <globaldefs.h>

extern "C" void func_020301c8(int a, int handle);
int GetData02104304Field4();

struct Obj0208becc {
    char pad0[0xbc];
    int handle;              // 0xbc
    char pad1[0x12];         // 0xc0..0xd1
    short field_d2;          // 0xd2
    char pad2[2];            // 0xd4..0xd5
    unsigned char field_d6;  // 0xd6
    char pad3[3];            // 0xd7..0xd9
    unsigned short flags_da; // 0xda
    char pad4[1];            // 0xdc
    unsigned char field_dd;  // 0xdd
};

// USA: func_0208becc
ARM void SetFieldD2IfChanged0208becc(struct Obj0208becc* obj, int value, unsigned char b) {
    if (value < 0) return;
    if (obj->field_d2 == value) return;
    obj->field_d2 = value;
    obj->field_dd = b;
    if (obj->handle >= 0) {
        int owner = GetData02104304Field4();
        func_020301c8(owner, obj->handle);
        obj->handle = -1;
    }
    obj->flags_da |= 0x20;
    obj->field_d6 = 0;
}
