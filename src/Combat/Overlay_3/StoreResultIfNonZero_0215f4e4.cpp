#include <globaldefs.h>

extern "C" int func_ov003_0215f4a4(void*);

// USA: func_ov003_0215f4e4
ARM void StoreResultIfNonZero_0215f4e4(int* obj) {
    int result = func_ov003_0215f4a4(obj);
    if (result != 0) {
        *obj = result;
    }
}
