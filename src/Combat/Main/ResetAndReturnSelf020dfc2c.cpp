#include <globaldefs.h>

struct Struct020dfc40;
void ResetStruct020dfc40(struct Struct020dfc40* p);

// USA: func_020dfc2c
ARM void* ResetAndReturnSelf020dfc2c(void* p) {
    ResetStruct020dfc40((struct Struct020dfc40*)p);
    return p;
}
