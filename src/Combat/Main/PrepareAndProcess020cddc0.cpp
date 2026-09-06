#include <globaldefs.h>

extern "C" void func_020cdc7c(void* obj);
extern "C" int func_020cdfd8(void* a, void* b);

// USA: func_020cddc0
ARM int PrepareAndProcess020cddc0(void* obj) {
    func_020cdc7c(obj);
    return func_020cdfd8(obj, obj);
}
