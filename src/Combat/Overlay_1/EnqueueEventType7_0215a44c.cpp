#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov001_02159f54(void*);

// USA: func_ov001_0215a44c
ARM void* EnqueueEventType7_0215a44c(void* ctx, int a, int b, int c) {
    void* node = func_ov001_02159f54(ctx);
    if (node != NULL) {
        *(int*)node = 7;
        node = memcpy((char*)node + 4, &a, 0xc);
    }
    return node;
}
