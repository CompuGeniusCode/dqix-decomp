#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
extern "C" void* func_ov017_0218b5b0(void);
void EnqueueEventTag33_021d2738(unsigned char a, unsigned char b);

// USA: func_ov017_021c12b0
ARM void EnqueueTag33ForListedCombatant_021c12b0(unsigned char param) {
	void* self = func_ov017_0218b5b0();
	int* list = *(int**)((char*)self + 0x3000 + 0x71c);
	short id = *(short*)((char*)list + 0x22);
	struct BattleStruct* bs = GetBattleStruct();
	struct CombatantStruct* c = GetCombatantWithFlag0x800(bs, id);
	if (c == NULL) {
		c = GetCombatantAtField0x3ac(bs);
	}
	short val = *(short*)((char*)c + 4);
	EnqueueEventTag33_021d2738((unsigned char)(val & 0xff), param);
}
