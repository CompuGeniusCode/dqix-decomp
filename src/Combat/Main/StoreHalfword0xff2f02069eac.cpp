#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02069eac { void* dest; };

// USA: func_02069eac
ARM int StoreHalfword0xff2f02069eac(struct Obj02069eac* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff2f;
    memcpy(d, &v, 2);
    return 2;
}
