#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"

struct Element0x318_02028bac { unsigned char data[0x318]; };
struct Element0x318_02028bac* GetElementStride0x318(struct Element0x318_02028bac* base, int index);
struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase(void);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" void func_020733d8(void* elem, int mode);

struct EntryFlags_021a205c { unsigned short pad0 : 3; unsigned short flag3 : 1; unsigned short pad4 : 12; };

// USA: func_ov017_021a205c
ARM void ProcessFlaggedCombatants800_021a205c(void) {
	struct BattleStruct* battleStruct = GetBattleStruct();
	struct Element0x318_02028bac* table = (struct Element0x318_02028bac*)GetEntryTableBase();
	(int)BackgroundLoader::GetInstance();
	for (int i = 0; i < 4; i++) {
		GetCombatantWithFlag0x800(battleStruct, i);
		struct Element0x318_02028bac* elem = GetElementStride0x318(table, i);
		struct EntryFlags_021a205c* flags = (struct EntryFlags_021a205c*)((unsigned char*)elem + 2);
		if (flags->flag3) {
			func_020733d8(elem, 0);
		}
	}
}
