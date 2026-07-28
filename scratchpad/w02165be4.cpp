#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
extern "C" int func_ov004_02164738(void* obj);

// USA: func_ov004_02165be4
ARM int Function_02165be4(void* a1) {
    ReinitController02043204((char*)GetGlobalField0x1c020421a0());
    func_ov004_02164738(a1);
    return 0;
}
