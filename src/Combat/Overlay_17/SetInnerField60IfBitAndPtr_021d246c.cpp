#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);

// USA: func_ov017_021d246c
ARM void SetInnerField60IfBitAndPtr_021d246c(int unusedA, char* b, struct BattleStruct* battleStruct, char* d) {
	struct CombatantStruct* c = GetCombatantAtField0x397c(battleStruct);
	int* p = *(int**)((char*)c + 0x130);
	if (*p & 1) {
		int* inner = *(int**)(d + 0x3000 + 0xb0c);
		if (inner != 0) {
			*(int*)((char*)inner + 0x60) = *(int*)(b + 4);
		}
	}
}
