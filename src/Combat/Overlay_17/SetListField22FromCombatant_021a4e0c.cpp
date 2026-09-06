#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
extern "C" void func_ov017_021c12fc(char* obj, int a, int b);

// USA: func_ov017_021a4e0c
ARM void SetListField22FromCombatant_021a4e0c(char* obj) {
	struct CombatantStruct* c = GetCombatantAtField0x397c(GetBattleStruct());
	if (c == NULL) {
		return;
	}
	short val = *(short*)((char*)c + 4);
	int* list = *(int**)(obj + 0x3000 + 0x71c);
	*(short*)((char*)list + 0x22) = val;
	func_ov017_021c12fc(obj, 1, 1);
}
