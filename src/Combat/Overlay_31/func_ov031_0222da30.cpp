#include <globaldefs.h>

extern unsigned char GetField60_02225c24(void);
extern void SetField_022274c0_022274c0(int);
extern void CallStubPair_0222da50(void);

// USA: func_ov031_0222da30  (semantic: AdvanceUnlessField60Is31_0222da30)
extern "C" ARM void func_ov031_0222da30(void) {
	if (GetField60_02225c24() == 0x1f) return;
	SetField_022274c0_022274c0((int)CallStubPair_0222da50);
}
