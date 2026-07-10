#include <globaldefs.h>

void ClearAndResetState020d8a48(void* obj);

// USA: func_020d95f8
ARM void ClearWordThenResetState020d95f8(int* p) {
    *p++ = 0;
    ClearAndResetState020d8a48(p);
}
