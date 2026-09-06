#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase(void);
extern "C" void* func_0202ae18(void);
struct CombatantStruct* GetCombatantWithFlag0x20(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
int CheckField0NonZero(int* obj);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void func_02076a8c(void* obj);
extern "C" void _ZN8Object3D10MakeHiddenEv(unsigned char* obj);
extern "C" void _ZN8Object3D7DestroyEv(unsigned char* obj);
extern "C" void _ZN8Object3D10InitializeEv(void* obj);

struct EntryArg_0219e014 { unsigned char pad0[2]; unsigned short field2 : 2; unsigned short pad3 : 14; };

// USA: func_ov017_0219e014
ARM void ProcessEntryFlagsAndCombatants_0219e014(unsigned char* obj, EntryArg_0219e014* entry) {
	struct BattleStruct* battleStruct = GetBattleStruct();
	GetEntryTableBase();
	void* search = func_0202ae18();

	if (entry) {
		for (int i = 0; i < 0xc; i++) {
			unsigned int idx = entry->field2;
			int combatantId = i + (idx * 0xc + 0x70);
			struct CombatantStruct* combatant = GetCombatantWithFlag0x20(battleStruct, combatantId);

			if (combatant) {
				if (CheckField0NonZero((int*)search) && GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search) != 0) {
					func_02076a8c(combatant);
					_ZN8Object3D10MakeHiddenEv((unsigned char*)combatant);
				} else {
					_ZN8Object3D7DestroyEv((unsigned char*)combatant);
				}
			}
		}
	}

	for (int i = 7; i <= 0x12; i++) {
		struct CombatantStruct* combatant = GetCombatantUnchecked(battleStruct, i);
		if (combatant) {
			_ZN8Object3D10InitializeEv(combatant);
			_ZN8Object3D10MakeHiddenEv((unsigned char*)combatant);
		}
	}
}
