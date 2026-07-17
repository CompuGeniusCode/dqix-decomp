#include <globaldefs.h>

extern "C" void func_02000b9c(unsigned int);
extern "C" int func_ov031_02204e38(void);
int DoInitAndMaybeCall_02204df8(void);
extern void* data_ov031_022496a4;

// USA: func_ov031_02204dbc
ARM int InitOnce_02204dbc(void* a) {
	func_02000b9c(0x2000c1c);
	if (data_ov031_022496a4 != NULL) return 0;
	data_ov031_022496a4 = a;
	func_ov031_02204e38();
	return DoInitAndMaybeCall_02204df8();
}
