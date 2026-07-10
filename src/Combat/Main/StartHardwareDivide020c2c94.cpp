#include <globaldefs.h>

struct HwDivRegs020c2c94 {
    unsigned short ctrl;
    unsigned char pad[0xe];
    long long numer;
    long long denom;
};

// USA: func_020c2c94
ARM void StartHardwareDivide020c2c94(int denom) {
    struct HwDivRegs020c2c94* r = (struct HwDivRegs020c2c94*)0x4000280;
    r->ctrl = 1;
    r->numer = 0x100000000000LL;
    r->denom = (unsigned int)denom;
}
