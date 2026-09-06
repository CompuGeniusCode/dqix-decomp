#include <globaldefs.h>

extern "C" char* func_ov017_0218b5b0(void);

// USA: func_ov001_0215fef4
ARM int ClearGlobalField1584_0215fef4(void) {
	*(int*)((func_ov017_0218b5b0() + 0x3000) + 0x630) = 0;
	return 1;
}
