#include <globaldefs.h>

// USA: func_ov003_02169658
ARM void ClearFlagFields_02169658(void* obj) {
    unsigned char* p = (unsigned char*)obj;
    p[0x59c] = 0;
    p[0x59d] = 0;
    p[0x59e] = 0;
    p[0x5a6] = 0;
    p[0x5a7] = 0;
}
