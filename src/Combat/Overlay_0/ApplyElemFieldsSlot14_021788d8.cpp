#include <globaldefs.h>
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0();
extern "C" void func_ov000_02178938(void* obj, int a, int b, void* buf);
struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0*, int, int, int, unsigned char);

// USA: func_ov000_021788d8
ARM void ApplyElemFieldsSlot14_021788d8(void* obj, int a, int b) {
    if (a == 0) return;
    void* buf = *(void**)(GetGlobalField0x1c020421a0() + 0x5c);
    memset(buf, 0, 0x960);
    func_ov000_02178938(obj, a, b, buf);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x188), 0xe, (int)buf, 1, 0);
}
