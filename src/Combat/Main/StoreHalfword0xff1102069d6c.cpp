#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02069d6c { void* dest; };

// USA: func_02069d6c
ARM int StoreHalfword0xff1102069d6c(struct Obj02069d6c* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff11;
    memcpy(d, &v, 2);
    return 2;
}
