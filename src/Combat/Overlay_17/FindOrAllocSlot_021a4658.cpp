#include <globaldefs.h>

void Init021b2f64(unsigned char* self);

// USA: func_ov017_021a4658  (semantic: FindOrAllocSlot_021a4658)
extern "C" ARM unsigned char* func_ov017_021a4658(unsigned char* base, int val) {
    int i;
    for (i = 0; i < 0xc; i++) {
        unsigned char* elem = base + i * 0x48;
        if (elem[0x373e] != 0) {
            if (elem[0x373f] == 0 && val == *(short*)(elem + 0x3744)) {
                return base + 0x373c + i * 0x48;
            }
        }
    }

    int j;
    for (j = 0; j < 0xc; j++) {
        unsigned char* elem = base + j * 0x48;
        if (elem[0x373e] == 0) {
            unsigned char* target = base + 0x373c + j * 0x48;
            Init021b2f64(target);
            return base + 0x373c + j * 0x48;
        }
    }

    for (;;) {}
}
