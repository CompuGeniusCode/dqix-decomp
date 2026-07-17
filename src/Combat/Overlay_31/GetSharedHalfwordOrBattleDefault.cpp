#include <globaldefs.h>

ARM int GetSharedHalfwordOrBattleDefault(void);
void FreeAndClearPtr_0223cf70(int*);
extern int data_ov031_02290cf8;

// USA: func_ov031_022357b4
ARM void WaitFor8000Then0223cf70_022357b4(void) {
	if (data_ov031_02290cf8 == 0) return;
	while (GetSharedHalfwordOrBattleDefault() != 0x8000) { }
	FreeAndClearPtr_0223cf70(&data_ov031_02290cf8);
}
