#include <globaldefs.h>

extern "C" int func_020bc948(void *obj, int a, int b);

// USA: func_020bf29c
ARM int AcquireRefAt0x120(void *obj, int a, int b) {
    if (*(int *)((char *)obj + 0x120) == 0) {
        if (func_020bc948(obj, a, b) == 0) return 0;
    }
    *(int *)((char *)obj + 0x120) += 1;
    return 1;
}
