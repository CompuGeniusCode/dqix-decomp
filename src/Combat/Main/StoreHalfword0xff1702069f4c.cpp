#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02069f4c { void* dest; };

// USA: func_02069f4c
ARM int StoreHalfword0xff1702069f4c(struct Obj02069f4c* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff17;
    memcpy(d, &v, 2);
    return 2;
}
