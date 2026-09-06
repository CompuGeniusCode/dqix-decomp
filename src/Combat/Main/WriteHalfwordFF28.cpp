#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02069974 { char* dst; };

// USA: func_02069974
ARM int WriteHalfwordFF28(struct Obj02069974* obj) {
    char* d = obj->dst;
    unsigned short v = 0xff28;
    memcpy(d, &v, 2);
    return 2;
}
