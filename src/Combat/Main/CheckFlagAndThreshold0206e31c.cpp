#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);

// USA: func_0206e31c
ARM int CheckFlagAndThreshold0206e31c(int unused, int index) {
    if (func_0202c540(func_0202ae18())) {
        if (index < 0xae) return 0;
    }
    return 1;
}
