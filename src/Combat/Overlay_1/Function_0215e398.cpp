#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);
extern "C" void func_02043124(char* obj);
void ReinitController02043204(char* obj);

// USA: func_ov001_0215e398
ARM int Function_0215e398(void) {
	int v = GetGlobalField0x1c020421a0();
	func_02043124((char*)v);
	ReinitController02043204((char*)v);
	return 1;
}
