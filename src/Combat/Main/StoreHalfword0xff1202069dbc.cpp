#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02069dbc { void* dest; };

// USA: func_02069dbc
ARM int StoreHalfword0xff1202069dbc(struct Obj02069dbc* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff12;
    memcpy(d, &v, 2);
    return 2;
}
