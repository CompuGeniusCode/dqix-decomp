#include <globaldefs.h>

extern "C" int _s32_div_f(int a, int b);
extern "C" void StoreSignedPairWithFlag020c5100(unsigned short* dst, int flag, int value);
extern "C" void func_ov023_021dacd4(void* obj, int a, int b);

struct Obj_021dac40 {
    char pad0[0xd98];
    short field_d98;
    char pad_after[0xd9c - 0xd9a];
    int field_d9c;
};

// USA: func_ov023_021dac40
ARM void UpdateTimerAndDispatch_021dac40(struct Obj_021dac40* obj, int delta) {
    if (!(obj->field_d9c & 0x10000)) return;

    short v = obj->field_d98 - delta;
    obj->field_d98 = v;
    v = obj->field_d98;
    if (v < 0) {
        v = 0;
        obj->field_d98 = v;
    }
    if (obj->field_d9c & 0x800000) {
        v = obj->field_d98;
        int q = _s32_div_f(v * 31, 90);
        func_ov023_021dacd4(obj, 0, 31 - q);
    } else {
        v = obj->field_d98;
        int q = _s32_div_f(-((90 - v) * 16), 90);
        StoreSignedPairWithFlag020c5100((unsigned short*)0x4000050, 0x16, q);
    }
}
