#include <globaldefs.h>

extern "C" char* func_ov031_022133f8(int);
extern "C" int func_ov031_02218fa0(void*);
void SetFieldCAndA_022134cc(int);

// USA: func_ov031_0221544c
ARM int SetFieldOrFail_0221544c(void) {
	if (!func_ov031_02218fa0(func_ov031_022133f8(8))) return 0xe;
	SetFieldCAndA_022134cc(3);
	return 0x11;
}
