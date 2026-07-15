#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
void* GetPtrField0x114(void* obj);
struct ColorHolder0204bd7c;
unsigned short ConvertColorToDecimalOffset30000(struct ColorHolder0204bd7c* obj);
void* GetPtrField0x468(void* obj);
struct SearchList02099a68;
int FindKeyGetBitflag02099a68(struct SearchList02099a68* list, unsigned short key);

// USA: func_ov017_021a26e8
ARM int GetBitflagForCombatantColor_021a26e8(int unused0, int combatantId) {
	struct BattleStruct* bs = GetBattleStruct();
	struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, combatantId);
	if (combatant == NULL) {
		return 0;
	}
	void* p114 = GetPtrField0x114(combatant);
	if (p114 == NULL) {
		return 0;
	}
	unsigned short color = ConvertColorToDecimalOffset30000((struct ColorHolder0204bd7c*)p114);
	void* list = GetPtrField0x468(bs);
	return FindKeyGetBitflag02099a68((struct SearchList02099a68*)list, color);
}
