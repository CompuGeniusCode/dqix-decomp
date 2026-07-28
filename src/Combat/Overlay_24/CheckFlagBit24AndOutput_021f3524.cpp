#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400ByID(int unused, int id);
struct FlagObj_021dd260;
int IsFlagBit24Set_021dd260(struct FlagObj_021dd260* obj);

struct Wrapper_021f3524 { int field0; };

// USA: func_ov024_021f3524  (semantic: CheckFlagBit24AndOutput_021f3524)
extern "C" ARM int func_ov024_021f3524(struct Wrapper_021f3524* a, int id, int unused2, int* outFlag, short* outId) {
	struct CombatantStruct* c = GetCombatantWithFlag0x400ByID(a->field0, id);
	if (!c) return 0;
	int result;
	if (IsFlagBit24Set_021dd260((struct FlagObj_021dd260*)c)) {
		result = 0;
	} else {
		result = 1;
		*outFlag = result;
		*outId = (short)id;
	}
	return result;
}
