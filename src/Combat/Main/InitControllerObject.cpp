#include <globaldefs.h>
void InitCombatSlots02043040(char*);
void ReinitEightSubStructsAndAllocator(char*);

extern "C" void func_02043224(void* self);
extern "C" void func_02043124(void* self);
void ResetControllerState020430b0(char* self);

// USA: func_02043000
ARM void InitControllerObject(char* self) {
    ReinitEightSubStructsAndAllocator((char*)(self + 0x19e0));
    func_02043224(self);
    InitCombatSlots02043040((char*)(self));
    func_02043124(self);
    ResetControllerState020430b0(self);
    *(int*)(self + 0x38) = 0;
}
