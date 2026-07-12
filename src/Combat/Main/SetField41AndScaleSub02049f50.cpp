#include <globaldefs.h>

struct Bits41_37474;
int GetField0x41Bits0To4(struct Bits41_37474* obj);
void ScaleU5ValueToU16(unsigned short* out, float val);
extern "C" void func_02034b34(void* p, int val, int count);

struct Obj02049f50 {
    unsigned char pad1[0x41];
    unsigned char field41;
    unsigned char pad2[0x13c - 0x42];
    unsigned char* sub;
};

#pragma optimize_for_size off
// USA: func_02049f50
ARM void SetField41AndScaleSub02049f50(struct Obj02049f50* obj, int val, int count) {
    if (count <= 0) {
        obj->field41 = (obj->field41 & ~0x1f) | ((unsigned char)val & 0x1f);
    }
    if (obj->sub == NULL) return;
    int x = GetField0x41Bits0To4((struct Bits41_37474*)obj);
    float f = (float)x;
    ScaleU5ValueToU16((unsigned short*)(obj->sub + 0x60), f);
    func_02034b34(obj->sub + 0x60, val, count);
}
