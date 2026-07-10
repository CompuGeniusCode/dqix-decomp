#include <globaldefs.h>

extern int data_02104304[];
extern "C" void func_02030110(void* obj);

// USA: func_0202f7a8
ARM void CallFunc02030110OnGlobalObject() {
    void* obj = (void*)data_02104304[1];
    if (obj != NULL) {
        func_02030110(obj);
    }
}
