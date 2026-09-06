#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void _Z21ClearFieldBit02053fe4P9T02053fe4(void* obj, int field2, int flag);
extern "C" int _ZNK8Object3D7GetFlagEi(void* obj, int mask);
void* GetField0x3f8Address(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);

extern "C" void func_ov017_021c9e00(int i, int one1, int zero, int one2);

// USA: func_ov017_02191bdc
ARM void ClearMonsterFlagEntries_02191bdc(unsigned char* a, int b) {
	struct BattleStruct* battleStruct = GetBattleStruct();
	struct CombatantStruct* combatant = GetCombatantAtField0x397c(battleStruct);
	if (!combatant) return;
	if (*(short*)((char*)combatant + 0xac) != 0) return;
	if (_ZNK8Object3D7GetFlagEi(combatant, 0x8000000) != 0) return;
	if (b == 0) {
		unsigned char* fieldAddr = (unsigned char*)GetField0x3f8Address(battleStruct);
		unsigned char* q = *(unsigned char**)(a + 0x370c);
		if (q[2] != 0) return;
		if (fieldAddr[2] != 0) return;
	}
	unsigned char* entry = a + 0x9c + 0x4400;
	for (int i = 0; i < 4; entry += 4, i++) {
		if (entry[0] == 0) continue;
		struct CombatantStruct* c2 = GetCombatantWithFlag0x100(battleStruct, i);
		if (c2 != NULL) {
			_Z21ClearFieldBit02053fe4P9T02053fe4(c2, *(short*)(entry + 2), 1);
			func_ov017_021c9e00(i, 1, 0, 1);
		}
		entry[0] = 0;
		*(short*)(entry + 2) = 0;
	}
}
