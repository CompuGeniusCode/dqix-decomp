#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0217f8c0;
void* FindMatchingTableEntry0217f8c0(struct Struct0217f8c0* s);
extern "C" void func_ov000_021781f8(void*, void*);
int GetGlobalField0x1c020421a0();
extern "C" void func_ov000_0217831c(void*, void*);
struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

// USA: func_ov000_0217819c
ARM void ApplyElemFieldsSlot7_0217819c(void* obj) {
    void* entry = FindMatchingTableEntry0217f8c0((struct Struct0217f8c0*)obj);
    func_ov000_021781f8(obj, entry);
    void* buf = *(void**)(GetGlobalField0x1c020421a0() + 0x5c);
    memset(buf, 0, 0x960);
    func_ov000_0217831c(obj, buf);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x188), 7, (int)buf, 1, 0);
}
