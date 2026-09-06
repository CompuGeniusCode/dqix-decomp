#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02069d94 { void* dest; };

// USA: func_02069d94
ARM int StoreHalfword0xff1302069d94(struct Obj02069d94* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff13;
    memcpy(d, &v, 2);
    return 2;
}
