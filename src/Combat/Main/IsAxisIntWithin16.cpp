#include <globaldefs.h>

struct AxisFloats0203b5a0 {
    unsigned char pad0[0xc];
    float f0c;
    unsigned char pad10[8];
    float f18;
};

// USA: func_0203b5a0
ARM int IsAxisIntWithin16(struct AxisFloats0203b5a0* s, int axis) {
    int v = axis == 0 ? (int)s->f0c : (int)s->f18;
    return v > -16 && v < 16;
}
