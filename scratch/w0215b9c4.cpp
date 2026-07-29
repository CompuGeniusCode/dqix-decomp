#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_021d60f4(void*);
extern int AbsPlus159IfNegative0215ad2c(int x);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
void ResetAndUnlinkNode02037330(unsigned char* obj);
void ClearCombatantSlot(struct BattleStruct* battleStruct, int id);
extern "C" void func_ov001_0215acb4(void* p);

struct GlobalTable_0215b9c4 { int pad0; unsigned char* elems; };
extern GlobalTable_0215b9c4 data_ov001_02165880;

struct Entry_0215b9c4 { int type; int field4; char pad8[8]; };

// USA: func_ov001_0215b9c4
ARM int RemoveCombatantAndQueueEntries_0215b9c4(void* self) {
	struct BattleStruct* bs = GetBattleStruct();
	if (bs == 0) return 0;
	int id = AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4(self));
	struct CombatantStruct* combatant = GetCombatantUnchecked(bs, id);
	if (combatant == 0) return 0;
	ResetAndUnlinkNode02037330((unsigned char*)combatant);
	ClearCombatantSlot(bs, id);
	if (data_ov001_02165880.elems != 0) {
		int i;
		for (i = 0; i < 0x20; i++) {
			unsigned char* base = data_ov001_02165880.elems;
			int type = *(int*)(base + i * 0x10);
			if (type == 1) {
				struct Entry_0215b9c4* e = (struct Entry_0215b9c4*)base + i;
				if (id == e->field4) {
					func_ov001_0215acb4((void*)e);
				}
			}
		}
	}
	return 1;
}
