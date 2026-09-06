#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
extern "C" void func_ov017_0218b5b0(void);
int GetGlobalField0x1c020421a0();

// USA: func_ov017_021acce4
ARM void RunBattleTeardownSequence_021acce4(void) {
	GetBattleStruct();
	func_0202ae18();
	func_ov017_0218b5b0();
	GetGlobalField0x1c020421a0();
}
