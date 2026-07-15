#include <globaldefs.h>

// USA: func_ov025_021e1010
ARM void* FindByteMatch_021e1010(unsigned char* arr, int count, int val) {
    for (int i = 0; i < count; i++) {
        unsigned char* p = arr + i*0xc;
        if (val == p[0]) {
            return p;
        }
    }
    return 0;
}
