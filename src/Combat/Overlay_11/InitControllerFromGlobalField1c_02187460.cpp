#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);

// USA: func_ov011_02187460
ARM int InitControllerFromGlobalField1c_02187460(void) {
    char* obj = (char*)GetGlobalField0x1c020421a0();
    ReinitController02043204(obj);
    func_02043124(obj);
    return 1;
}
