#include <globaldefs.h>

extern "C" void func_020d9164(void* obj);
void ResetStateAtOffset4_020d960c(int* p);

// USA: func_02079a3c
ARM void* ResetObjectState02079a3c(void* obj) {
    func_020d9164(obj);
    ResetStateAtOffset4_020d960c((int*)obj);
    return obj;
}
