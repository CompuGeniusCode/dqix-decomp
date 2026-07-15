#include <globaldefs.h>
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0();
extern "C" void func_ov000_02177f74(void* obj, void* buf);

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

// USA: func_ov000_02177f28
ARM int ApplyElemFieldsSlot6(void* obj) {
	void* buf = *(void**)(GetGlobalField0x1c020421a0() + 0x5c);
	memset(buf, 0, 0x960);
	func_ov000_02177f74(obj, buf);
	return TryApplyElemFields0205d5d0((StructA0205d5d0*)((char*)obj + 0x188), 6, (int)buf, 1, 0);
}
