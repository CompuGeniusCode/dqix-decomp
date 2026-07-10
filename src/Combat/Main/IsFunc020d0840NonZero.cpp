#include <globaldefs.h>

extern "C" int func_020d0840(void);

// USA: func_02075ca0
ARM int IsFunc020d0840NonZero(void) {
    return func_020d0840() != 0;
}
