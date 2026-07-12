#include <globaldefs.h>
void ClearFirstField020d9164(int*);

void ResetStateAtOffset4_020d960c(int* p);

// USA: func_02079a3c
ARM void* ResetObjectState02079a3c(void* obj) {
    ClearFirstField020d9164((int*)(obj));
    ResetStateAtOffset4_020d960c((int*)obj);
    return obj;
}
