#include <globaldefs.h>

struct DeltaSelectorState020ccc10 {
    char pad[0x24];
    int min;    // 0x24
    int max;    // 0x28
    int value;  // 0x2c
};

// USA: func_020ccc10
ARM int AddDeltaBySelectorClampAt0x2c(struct DeltaSelectorState020ccc10* s, int value, int mode) {
    switch (mode) {
    case 0: value += s->min; break;
    case 1: value += s->value; break;
    case 2: value += s->max; break;
    default: return 0;
    }
    if (value < s->min) value = s->min;
    if (value > s->max) value = s->max;
    s->value = value;
    return 1;
}
