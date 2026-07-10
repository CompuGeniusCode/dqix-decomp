#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02069ce0 { void* dest; };

// USA: func_02069ce0
ARM int StoreHalfword0xff0f02069ce0(struct Obj02069ce0* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff0f;
    memcpy(d, &v, 2);
    return 2;
}
