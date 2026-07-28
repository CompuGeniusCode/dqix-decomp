#include <globaldefs.h>

extern char* data_ov031_02290cf8;
int GetSharedHalfwordOrBattleDefault(void);
extern "C" unsigned int func_ov031_0223cf70(void** a);

// USA: func_ov031_022357b4  (semantic: WaitForBattleDefaultThenFree_022357b4)
extern "C" ARM void func_ov031_022357b4(void) {
	if (data_ov031_02290cf8 == NULL) return;
	while (GetSharedHalfwordOrBattleDefault() != 0x8000) {}
	func_ov031_0223cf70((void**)0x02290cf8);
}
