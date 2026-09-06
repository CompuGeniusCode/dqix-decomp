#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_021d6134(void*, int);
unsigned char GetField0x397cValue(struct BattleStruct* battleStruct);

// USA: func_ov001_02161930
ARM int ForwardCombatantOrFallback_02161930(void* self) {
	struct BattleStruct* battle = GetBattleStruct();
	char* p = (char*)func_ov017_0218b5b0() + 0x3000;
	char* table = *(char**)(p + 0x734) + 0x100;
	int cid = *(signed char*)(table + 0x16);
	struct CombatantStruct* c = GetCombatantWithFlag0x100(battle, cid);
	int n = cid;
	if (c == NULL) {
		n = GetField0x397cValue(battle);
	}
	func_ov017_021d6134(self, n);
	return 1;
}
