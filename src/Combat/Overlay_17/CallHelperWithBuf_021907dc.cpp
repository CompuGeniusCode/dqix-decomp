#include <globaldefs.h>

struct Buf16_021907dc { int x[4]; };
extern "C" void func_ov017_02190884(int b, Buf16_021907dc* outBuf, int* zero, int c, int d, int e);

// USA: func_ov017_021907dc
ARM void CallHelperWithBuf_021907dc(int a, int b, int c, int d, int e) {
	Buf16_021907dc buf;
	int zero = 0;
	func_ov017_02190884(b, &buf, &zero, c, d, e);
}
