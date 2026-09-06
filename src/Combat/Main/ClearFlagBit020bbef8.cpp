#include <globaldefs.h>

struct FlagPool020bbef8 { int a; unsigned int flags; };
extern struct FlagPool020bbef8 data_0210f3c0;

// USA: func_020bbef8
ARM void ClearFlagBit020bbef8(int bit) {
    data_0210f3c0.flags &= ~(1 << bit);
}
