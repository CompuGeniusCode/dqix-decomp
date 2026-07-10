#include <globaldefs.h>

extern "C" void func_02043040(char* obj);
extern "C" void func_02043124(char* obj);
ARM void ResetControllerState020430b0(char* self);

// USA: func_02043204
ARM void ReinitController02043204(char* obj) {
    func_02043040(obj);
    func_02043124(obj);
    ResetControllerState020430b0(obj);
}
