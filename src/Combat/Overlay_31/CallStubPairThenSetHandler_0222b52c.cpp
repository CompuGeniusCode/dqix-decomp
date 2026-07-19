#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
void SetField_022274c0_022274c0(int v);
void CallStubPair_0222b550(void);

// USA: func_ov031_0222b52c  (semantic: CallStubPairThenSetHandler_0222b52c)
extern "C" ARM void func_ov031_0222b52c(void) {
	if (func_ov031_0223c054(0) != 0) return;
	SetField_022274c0_022274c0((int)CallStubPair_0222b550);
}
