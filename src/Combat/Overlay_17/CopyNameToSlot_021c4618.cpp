#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
void FormatAndCopyName02052958(char* obj, char* name, int shouldFormatSecond);

// USA: func_ov017_021c4618
ARM void CopyNameToSlot_021c4618(int unused0, char* obj, struct BattleStruct* bs, char* base) {
	unsigned char idx = obj[4];
	struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, idx);
	if (combatant == NULL) {
		return;
	}
	FormatAndCopyName02052958((char*)combatant, obj + 5, 1);
	char* dst = base + 0x435c + idx * 0x30;
	strcpy(dst, *(char**)((char*)combatant + 0x134));
}
