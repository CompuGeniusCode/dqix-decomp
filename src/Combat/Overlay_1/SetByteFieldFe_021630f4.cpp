#include <globaldefs.h>

extern "C" char* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d60f4(int a);

// USA: func_ov001_021630f4
ARM int SetByteFieldFe_021630f4(int a) {
	char* p = *(char**)(func_ov017_0218b5b0() + 0x3000 + 0x734);
	*(unsigned char*)(p + 0xfe) = func_ov017_021d60f4(a) != 0 ? 1 : 0;
	return 1;
}
