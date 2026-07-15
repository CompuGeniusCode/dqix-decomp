#include <globaldefs.h>

struct Bitfield021f5524 {
    unsigned int value : 12;
};

// USA: func_ov023_021f5524
ARM unsigned int GetValueTimes4_021f5524(struct Bitfield021f5524 *obj) {
    return obj->value * 4;
}
