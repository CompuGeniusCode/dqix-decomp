#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

unsigned short GetTableValue(void* obj);

struct StatsByte0x3b_021eb3e0 {
	char unk[0x3b];
	unsigned char byte0x3b;
};

// USA: func_ov024_021eb3e0  (semantic: SetCombatantFaceIconByTableValue_021eb3e0)
extern "C" ARM void func_ov024_021eb3e0(void* unused, int combatantId) {
	struct BattleStruct* battle = GetBattleStruct();
	struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battle, combatantId);
	if (combatant == NULL) {
		return;
	}
	struct StatsByte0x3b_021eb3e0* stats;
	unsigned short value = GetTableValue(combatant);
	if (value >= 0x4b) {
		stats = (struct StatsByte0x3b_021eb3e0*)combatant->currentStats;
		stats->byte0x3b = (stats->byte0x3b & ~0xf0) | 0xa0;
		return;
	}
	value = GetTableValue(combatant);
	if (value >= 0x32) {
		stats = (struct StatsByte0x3b_021eb3e0*)combatant->currentStats;
		stats->byte0x3b = (stats->byte0x3b & ~0xf0) | 0x90;
		return;
	}
	value = GetTableValue(combatant);
	stats = (struct StatsByte0x3b_021eb3e0*)combatant->currentStats;
	if (value >= 0x19) {
		unsigned char b = *(volatile unsigned char*)&stats->byte0x3b;
		stats->byte0x3b = (b & ~0xf0) | 0x80;
	} else {
		unsigned char b = *(volatile unsigned char*)&stats->byte0x3b;
		stats->byte0x3b = (b & ~0xf0) | 0x70;
	}
}
