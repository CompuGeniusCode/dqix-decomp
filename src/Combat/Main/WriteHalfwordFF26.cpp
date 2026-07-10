#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02069924 { char* dst; };

// USA: func_02069924
ARM int WriteHalfwordFF26(struct Obj02069924* obj) {
    char* d = obj->dst;
    unsigned short v = 0xff26;
    memcpy(d, &v, 2);
    return 2;
}
