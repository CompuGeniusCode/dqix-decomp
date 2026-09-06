#include <globaldefs.h>
#include "std_library_functions.h"

struct S021f9c0c { char pad[0x20]; void* ptr; unsigned short w; unsigned short h; };

// USA: func_ov023_021f9c0c
ARM void* ClearBuffer_021f9c0c(struct S021f9c0c* obj) {
    unsigned short w = obj->w;
    unsigned short h = obj->h;
    void* ptr = obj->ptr;
    return memset(ptr, 0, h * (w * 2));
}
