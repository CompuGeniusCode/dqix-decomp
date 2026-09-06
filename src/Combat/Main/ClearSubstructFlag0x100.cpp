#include <globaldefs.h>

// USA: func_02048c50
ARM void ClearSubstructFlag0x100(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        p[8] &= ~0x100;
    }
}
