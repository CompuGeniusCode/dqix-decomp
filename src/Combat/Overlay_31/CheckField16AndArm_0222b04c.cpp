#include <globaldefs.h>

int GetField16_02222e0c(void);
void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);
void RunUpdateAndTwoChecks_0222b36c(void);
void SetField_022274c0_022274c0(int a);
extern "C" void func_ov031_0222b094(void);

extern char data_ov031_02290c80;

// USA: func_ov031_0222b04c  (semantic: CheckField16AndArm_0222b04c)
extern "C" ARM void func_ov031_0222b04c(void) {
	if (GetField16_02222e0c() == -2) return;
	void* result = CallWithZeroExtra_0223e218((void*)1, (void*)RunUpdateAndTwoChecks_0222b36c, (void*)0, 0x78);
	*(int*)((&data_ov031_02290c80) + 4) = (int)result;
	SetField_022274c0_022274c0((int)func_ov031_0222b094);
}
