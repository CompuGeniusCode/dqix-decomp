#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(int a);
extern "C" char* func_ov017_0218b5b0(void);
extern "C" void func_ov017_0219b578(int a, int b, int c);

// USA: func_ov001_02160a48
ARM int Forward2Field0219b578_02160a48(int a) {
	int b = func_ov017_021d60f4(a);
	int c = func_ov017_021d60f4(a + 0x8);
	func_ov017_0219b578((int)func_ov017_0218b5b0(), b, c);
	return 1;
}
