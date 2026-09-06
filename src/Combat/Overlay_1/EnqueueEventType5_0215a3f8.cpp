#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov001_02159f14(void*);

// USA: func_ov001_0215a3f8
ARM void* EnqueueEventType5_0215a3f8(void* ctx, int a, int b, int c) {
    void* node = func_ov001_02159f14(ctx);
    if (node != NULL) {
        *(int*)node = 5;
        node = memcpy((char*)node + 4, &a, 0xc);
    }
    return node;
}
