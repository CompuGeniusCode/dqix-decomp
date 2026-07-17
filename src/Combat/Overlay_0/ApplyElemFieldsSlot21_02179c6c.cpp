#include <globaldefs.h>
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0();
struct Struct0217f8c0;
struct TableEntry0217f8c0;
struct TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(struct Struct0217f8c0* s);
extern "C" void func_ov000_02179cdc(void* obj, int id);
extern "C" void func_ov000_02179ed8(void* obj, void* entry, void* buf);
struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0*, int, int, int, unsigned char);

// USA: func_ov000_02179c6c
ARM void ApplyElemFieldsSlot21_02179c6c(void* obj, int id) {
    void* entry = FindMatchingTableEntry0217f8c0((struct Struct0217f8c0*)obj);
    func_ov000_02179cdc(obj, id);
    void* buf = *(void**)(GetGlobalField0x1c020421a0() + 0x5c);
    memset(buf, 0, 0x960);
    func_ov000_02179ed8(obj, entry, buf);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x188), 0x15, (int)buf, 1, 0);
}
