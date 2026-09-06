#include <globaldefs.h>
#include "std_library_functions.h"

struct MsgDst02069f74 { void* dst; };

// USA: func_02069f74
ARM int EmitControlCodeFF01(struct MsgDst02069f74* p) {
    void* d = p->dst;
    unsigned short code = 0xff01;
    memcpy(d, &code, 2);
    return 2;
}
