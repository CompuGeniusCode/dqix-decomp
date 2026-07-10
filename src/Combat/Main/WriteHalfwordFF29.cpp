#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj0206999c { char* dst; };

// USA: func_0206999c
ARM int WriteHalfwordFF29(struct Obj0206999c* obj) {
    char* d = obj->dst;
    unsigned short v = 0xff29;
    memcpy(d, &v, 2);
    return 2;
}
