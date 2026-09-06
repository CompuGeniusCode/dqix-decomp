#include <globaldefs.h>

void SetCombatModeFromCase020dc2d0(int mode);
extern "C" struct AxisFloats0203b5f8* func_ov017_0218b5b0(void);
void ClearFlags0xa97(unsigned char* base, int mask);

// USA: func_ov004_0216acf8  (semantic: ResetCombatModeAndClearFlag_0216acf8)
extern "C" ARM int func_ov004_0216acf8(void) {
	SetCombatModeFromCase020dc2d0(0);
	unsigned char* fieldObj = *(unsigned char**)((char*)func_ov017_0218b5b0() + 0x3000 + 0x6d0);
	ClearFlags0xa97(fieldObj, 1);
	return 0;
}
