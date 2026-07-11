#include <globaldefs.h>

extern "C" void func_02010288(void* obj, float value);

struct ScaledAccum02010240 {
    unsigned char pad0[0x3c4];
    unsigned int scale;   // 0x3c4
    unsigned char pad1[4];
    float value;          // 0x3cc
    unsigned char pad2[4];
    float rate;           // 0x3d4
    int active;           // 0x3d8
};

// USA: func_02010240
ARM void ApplyScaledRateIfActive(ScaledAccum02010240* obj) {
    if (obj->active == 0) return;
    func_02010288(obj, obj->value + (float)obj->scale * obj->rate);
}
