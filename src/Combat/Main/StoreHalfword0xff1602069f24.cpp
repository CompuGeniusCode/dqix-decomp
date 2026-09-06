#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02069f24 { void* dest; };

// USA: func_02069f24
ARM int StoreHalfword0xff1602069f24(struct Obj02069f24* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff16;
    memcpy(d, &v, 2);
    return 2;
}
