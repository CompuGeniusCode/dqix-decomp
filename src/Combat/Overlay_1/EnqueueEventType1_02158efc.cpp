#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov001_02158dcc(void*);

// USA: func_ov001_02158efc
ARM void* EnqueueEventType1_02158efc(void* ctx, int a, int b, int c) {
    void* node = func_ov001_02158dcc(ctx);
    if (node != NULL) {
        *(int*)node = 1;
        node = memcpy((char*)node + 4, &a, 0xc);
    }
    return node;
}
