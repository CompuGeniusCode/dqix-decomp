#include <globaldefs.h>

class Accum_021d8a74;
void AccumulateFixedAngle_021d8a74(Accum_021d8a74* obj, float angle);
void FillCombatBuffer021d8ad4(void* obj, char* buf);

struct Obj942c {
    float field0;
    char pad4[0x40 - 4];
    void* field40;
    char pad44[0x60 - 0x44];
    int f60;
    int f64;
    char pad68[0x80 - 0x68];
    unsigned char f80;
    unsigned char f81;
};

// USA: func_ov028_021d942c
extern "C" ARM void func_ov028_021d942c(Obj942c* obj, int val) {
    float f0 = obj->field0;
    float angle = (float)val * f0 * 0.5f;
    AccumulateFixedAngle_021d8a74((Accum_021d8a74*)((char*)obj + 0x60), angle);
    FillCombatBuffer021d8ad4((char*)obj + 0x60, (char*)obj->field40);
    if ((unsigned int)((obj->f64 >> 12) + 16) <= (unsigned int)(obj->f60 >> 12)) {
        obj->f80 = 3;
        obj->f81 = 0;
    }
}
