#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj0206994c { char* dst; };

// USA: func_0206994c
ARM int WriteHalfwordFF27(struct Obj0206994c* obj) {
    char* d = obj->dst;
    unsigned short v = 0xff27;
    memcpy(d, &v, 2);
    return 2;
}
