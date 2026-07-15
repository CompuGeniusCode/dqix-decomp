#include <globaldefs.h>
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0();
struct Struct0217f8c0;
struct TableEntry0217f8c0;
struct TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(struct Struct0217f8c0* s);
extern "C" void func_ov000_02179194(void* obj, void* entry);
extern "C" void func_ov000_0217936c(void* obj, void* entry, void* buf);

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

// USA: func_ov000_02179128
ARM int ApplyElemFieldsSlot16(void* obj) {
	void* entry = FindMatchingTableEntry0217f8c0((struct Struct0217f8c0*)obj);
	func_ov000_02179194(obj, entry);
	void* buf = *(void**)(GetGlobalField0x1c020421a0() + 0x5c);
	memset(buf, 0, 0x960);
	func_ov000_0217936c(obj, entry, buf);
	return TryApplyElemFields0205d5d0((StructA0205d5d0*)((char*)obj + 0x188), 0x10, (int)buf, 1, 0);
}
