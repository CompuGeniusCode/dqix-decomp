#include <globaldefs.h>

extern "C" int func_ov001_02164624(int a, int b);
extern "C" void func_ov001_02164578(int a, int b, void* c, int d, float e);
extern int data_ov001_02165884;

struct S02159a74 { char pad[0x10]; int field10; int field14; int field18; char pad2[0x3c - 0x1c]; int* field3c; };
struct S70 { char pad[0x70]; int field70; };

// USA: func_ov001_02159a74
ARM int func_ov001_02159a74(struct S02159a74* obj, struct S70* other) {
    int result;
    if (obj->field18 != 0) {
        result = 0;
    } else if (func_ov001_02164624(data_ov001_02165884, other->field70) == 0) {
        result = 1;
    } else {
        float f = (float)obj->field14;
        func_ov001_02164578(data_ov001_02165884, other->field70, (char*)obj + 0x1c, obj->field10, f);
        if (obj->field3c != NULL && *obj->field3c == 0xd) {
            result = 0;
        } else {
            obj->field18 = 1;
            result = 1;
        }
    }
    return result;
}
