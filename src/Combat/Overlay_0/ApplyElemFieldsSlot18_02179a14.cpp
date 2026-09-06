#include <globaldefs.h>
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0();
extern "C" void func_ov000_02179a70(void*, int, int, void*);
struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0*, int, int, int, unsigned char);

// USA: func_ov000_02179a14
ARM void ApplyElemFieldsSlot18_02179a14(void* obj, int a, int b) {
    void* buf = *(void**)(GetGlobalField0x1c020421a0() + 0x5c);
    memset(buf, 0, 0x960);
    func_ov000_02179a70(obj, a, b, buf);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x188), 0x12, (int)buf, 1, 0);
}
