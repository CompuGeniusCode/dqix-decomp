#include <globaldefs.h>

extern "C" int GetField40_02239be8(void);
void RunTagPairAndDispatch_0223a47c(void);
extern unsigned char* data_ov031_02290d20;

// USA: func_ov031_0223b010
ARM int TryMarkFlagA90IfField40Is1_0223b010(void) {
	if (GetField40_02239be8() != 1) {
		return 0;
	}
	RunTagPairAndDispatch_0223a47c();
	data_ov031_02290d20[0xa90] = 1;
	return 1;
}
