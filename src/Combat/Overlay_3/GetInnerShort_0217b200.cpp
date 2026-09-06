#include <globaldefs.h>

// USA: func_ov003_0217b200
ARM unsigned short GetInnerShort_0217b200(void** obj) {
    void* p = *obj;
    if (!p) {
        return 0;
    }
    return *(unsigned short*)p;
}
