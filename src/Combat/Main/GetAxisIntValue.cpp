#include <globaldefs.h>

struct AxisFloats0203b57c {
    unsigned char pad0[0xc];
    float f0c;
    unsigned char pad10[8];
    float f18;
};

// USA: func_0203b57c
ARM int GetAxisIntValue(struct AxisFloats0203b57c* s, int axis) {
    if (axis == 0) {
        return (int)s->f0c;
    }
    return (int)s->f18;
}
