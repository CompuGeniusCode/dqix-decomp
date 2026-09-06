#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150(unsigned char* obj);
extern "C" int _s32_div_f(int a, int b);

// USA: func_ov017_021920dc
#pragma optimize_for_size off
ARM int HasFieldSlotOrFlagBit27_021920dc(int unused, int id) {
	struct BattleStruct* battleStruct = GetBattleStruct();
	int result = 0;
	int idx = -1;
	int inRange = (id >= 0 && id <= 3);
	if (inRange) {
		idx = id;
	} else if (id >= 0x13 && id <= 0x67) {
		idx = _s32_div_f(id - 0x13, 0xc);
	}

	if (idx >= 0) {
		struct CombatantStruct* c = GetCombatantWithFlag0x100(battleStruct, idx);
		if (c != NULL) {
			int val = GetFieldAt0x150((unsigned char*)c);
			struct CombatantStruct* c2 = GetCombatantFromList(battleStruct, idx);
			if (val != 0 && *((unsigned char*)val + 0x56c) != 0) {
				goto setResult;
			}
			if (c2 != NULL && (*(unsigned int*)c2->currentStats->unk1 & 0x8000000) != 0) {
				goto setResult;
			}
			goto done;
setResult:
			result = 1;
done:
			;
		}
	}
	return result;
}
