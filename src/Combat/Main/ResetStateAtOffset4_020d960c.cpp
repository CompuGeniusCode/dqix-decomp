#include <globaldefs.h>

void ClearAndResetState020d8a48(void* obj);

// USA: func_020d960c
ARM void ResetStateAtOffset4_020d960c(int* p) {
    ClearAndResetState020d8a48(p + 1);
}
