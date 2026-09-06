#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct FieldPtrObj_021f5228 { char pad[0x150]; char *ptr150; };
int GetFieldAt0x150(unsigned char* obj);
int GetTableByte020dd11c(unsigned int a, unsigned int b);

// USA: func_ov023_021f5228
ARM int CheckThresholdOverAny_021f5228(int id) {
	struct BattleStruct *bs = GetBattleStruct();
	struct FieldPtrObj_021f5228 *combatant = (struct FieldPtrObj_021f5228*)GetCombatantWithFlag0x100(bs, id);
	if (!combatant) return 0;
	int field150 = GetFieldAt0x150((unsigned char*)combatant);
	if (!field150) return 0;
	int val = *(int*)(combatant->ptr150 + 0x950);
	unsigned int byteVal = val & 0xff;
	for (int i = 0; i < 5; i++) {
		int idx = GetTableByte020dd11c(byteVal, i & 0xff);
		unsigned char *base = (unsigned char*)(field150 + idx);
		if (base[0x464] < 0x64) return 1;
	}
	return 0;
}
