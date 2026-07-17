#include <globaldefs.h>
#include "std_library_functions.h"

extern unsigned char data_02114e54;

extern "C" void func_ov023_021da100(void* obj, void* buf, int flag);

struct StructA0205d5d0;
extern "C" int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

struct Obj_021da1dc {
    char pad0[0xf8];
    void* field_f8;
    char pad1[0x2e8 - 0xfc];
    int field_2e8;
    char pad2[0xd85 - 0x2ec];
    unsigned char field_d85;
};

// USA: func_ov023_021da1dc
ARM void ResetAndApplyElemFields_021da1dc(struct Obj_021da1dc* obj) {
    unsigned char mode = obj->field_d85;
    if (mode == 0) return;

    int useDefault = 0;
    if (mode == 2) {
        unsigned char b5f = (&data_02114e54)[0x5f];
        if (b5f != 0 && *(unsigned short*)((char*)&data_02114e54 + 0x24) != 0) {
            if (obj->field_2e8 < 0) return;
            useDefault = 1;
        }
    }

    void* buf = obj->field_f8;
    memset(buf, 0, 0x960);
    func_ov023_021da100(obj, buf, useDefault);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x2b4), 1, (int)buf, 0, 1);
}
