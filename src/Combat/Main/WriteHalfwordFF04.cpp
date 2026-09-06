#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02069ae4 { char* dst; };

// USA: func_02069ae4
ARM int WriteHalfwordFF04(struct Obj02069ae4* obj) {
    char* d = obj->dst;
    unsigned short v = 0xff04;
    memcpy(d, &v, 2);
    return 2;
}
