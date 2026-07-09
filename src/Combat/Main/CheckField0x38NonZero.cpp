#include <globaldefs.h>

struct S_377d4 {
    char pad[0x38];
    int f38;
};

// USA: func_020377d4
ARM int CheckField0x38NonZero(struct S_377d4* obj) {
    return obj->f38 != 0;
}
