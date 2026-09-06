#include <globaldefs.h>

int GetField16_02222e0c(void);
extern "C" void func_ov031_0223e2c0(int, int);
void SetField18_02222e98(void);
void SetField_022274c0_022274c0(int);
void RunStageThenResetAndDispatch_0222b420(void);

struct Struct0222b1a4 { unsigned char pad[4]; int field4; };
extern Struct0222b1a4 data_ov031_02290c80;

// USA: func_ov031_0222b1a4  (semantic: FireCallbackAndReset_0222b1a4)
extern "C" ARM void func_ov031_0222b1a4(void) {
	if (GetField16_02222e0c() != 0) return;
	int v = data_ov031_02290c80.field4;
	if (v == 0) return;
	func_ov031_0223e2c0(1, v);
	data_ov031_02290c80.field4 = 0;
	SetField18_02222e98();
	SetField_022274c0_022274c0((int)RunStageThenResetAndDispatch_0222b420);
}
