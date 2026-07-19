#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222d9a4(void);

struct Obj0222e3a4 { unsigned char pad[4]; int *field4; };
extern Obj0222e3a4 *data_ov031_02290c98;

// USA: func_ov031_0222e3a4  (semantic: ClearFlagBitsUnlessActive_0222e3a4)
extern "C" ARM void func_ov031_0222e3a4(void) {
	if (func_ov031_02237eb0() != 0) return;
	int *p = data_ov031_02290c98->field4;
	*p = *p & 0xc1fffcff;
	SetField_022274c0_022274c0((int)func_ov031_0222d9a4);
}
