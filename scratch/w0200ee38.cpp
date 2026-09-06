#include <globaldefs.h>

// USA: func_0200ee38
extern "C" ARM void RunCallbackFromHiToLo0200ee38(unsigned int lo, unsigned int hi, unsigned int step, void (*fn)(unsigned int)) {
    struct { void* self; int pad[5]; } local;
    local.self = &local;
    if (hi > lo) {
        do {
            hi -= step;
            fn(hi);
        } while (hi > lo);
    }
}
