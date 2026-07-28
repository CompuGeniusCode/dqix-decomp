#include <globaldefs.h>

typedef void (*CtorFunc0200edc8)(void);
extern CtorFunc0200edc8 data_020eeb18[];

// USA: func_0200edc8  (semantic: RunStaticInitializers0200edc8)
extern "C" ARM void func_0200edc8(void) {
    CtorFunc0200edc8* p = data_020eeb18;
    while (p != 0 && *p != 0) {
        (*p)();
        p++;
    }
}
