#include <globaldefs.h>

extern "C" void func_02000b9c(int);
extern "C" int func_ov016_0218e800(int, int, int);

// USA: func_ov016_0218e528
ARM int CallStubAndForward_0218e528(int a, int b, int c) {
	func_02000b9c(0x2000bdc);
	return func_ov016_0218e800(a, b, c);
}
