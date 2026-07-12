#include <globaldefs.h>

extern "C" void func_0202f1dc(void* p);
extern "C" void func_02043224(void* self);
extern "C" void func_02043040(void* self);
extern "C" void func_02043124(void* self);
void ResetControllerState020430b0(char* self);

// USA: func_02043000
ARM void InitControllerObject(char* self) {
    func_0202f1dc(self + 0x19e0);
    func_02043224(self);
    func_02043040(self);
    func_02043124(self);
    ResetControllerState020430b0(self);
    *(int*)(self + 0x38) = 0;
}
