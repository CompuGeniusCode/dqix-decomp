#include <globaldefs.h>

struct AxisFloats0203b5f8 {
    unsigned char pad0[0xc];
    float f0c;
    unsigned char pad10[8];
    float f18;
};

// USA: func_0203b5f8
ARM int IsAxisIntZero(struct AxisFloats0203b5f8* s, int axis) {
    int v = axis == 0 ? (int)s->f0c : (int)s->f18;
    return v == 0;
}
