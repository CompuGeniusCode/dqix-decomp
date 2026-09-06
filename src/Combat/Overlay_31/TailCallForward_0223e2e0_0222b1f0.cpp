#include <globaldefs.h>

void SetField18_02222e98(void);
ARM int TailCallForward_0223e2e0(int, void*);
extern "C" void func_ov031_0223c278(int);
extern void SetField_022274c0_022274c0(int);
extern void RegisterCallback_0222b22c(void);

struct Struct0222b1f0 { unsigned char pad[4]; int field4; };
extern Struct0222b1f0 data_ov031_02290c80;

// USA: func_ov031_0222b1f0  (semantic: SetupAndTailCallThenSetHandler_0222b1f0)
extern "C" ARM void func_ov031_0222b1f0(void) {
	SetField18_02222e98();
	if (data_ov031_02290c80.field4 != 0) {
		TailCallForward_0223e2e0(1, (void*)data_ov031_02290c80.field4);
	}
	func_ov031_0223c278(8);
	SetField_022274c0_022274c0((int)RegisterCallback_0222b22c);
}
