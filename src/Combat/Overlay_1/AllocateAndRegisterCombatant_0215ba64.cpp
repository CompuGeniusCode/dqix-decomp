#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"

extern int GetData02104304Field4();
extern "C" int func_ov017_021d60f4(void*);
extern int AbsPlus159IfNegative0215ad2c(int x);
extern SafeAllocator* data_ov001_021658b8[8];
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
extern "C" void func_02034bc4(void* obj);
extern "C" void func_02036d88(void* node, void* buf);
void RegisterCombatantSlot(struct BattleStruct* battleStruct, int id, struct CombatantStruct* combatant);
struct Shorts5c_374e0;
void SetShorts0x5cTo0x60(struct Shorts5c_374e0* obj, short a, short b, short c);
extern "C" void func_020370a0(void* self, int a, int b);

// USA: func_ov001_0215ba64
ARM int AllocateAndRegisterCombatant_0215ba64(char* self, int type) {
	struct BattleStruct* bs = GetBattleStruct();
	GetData02104304Field4();

	int id1 = AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4(self));
	int id2 = AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4(self + 0x8));

	int sel = 0;
	if (type >= 3) {
		sel = func_ov017_021d60f4(self + 0x10);
	}

	SafeAllocator* allocator = data_ov001_021658b8[sel];

	struct CombatantStruct* combatant = GetCombatantUnchecked(bs, id1);
	if (combatant == NULL) return 0;

	void* newObj = allocator->Allocate(0xac);
	if (newObj == NULL) return 0;

	func_02034bc4(newObj);
	func_02036d88(combatant, newObj);
	RegisterCombatantSlot(bs, id2, (struct CombatantStruct*)newObj);
	SetShorts0x5cTo0x60((struct Shorts5c_374e0*)newObj, 0x10a, 0x10a, 0x10a);
	func_020370a0(newObj, 0, 0);
	return 1;
}
