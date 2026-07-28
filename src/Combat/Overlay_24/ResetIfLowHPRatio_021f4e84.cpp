#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

struct CombatantStruct* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" float func_ov024_021db358(struct CombatantStruct* obj);

// USA: func_ov024_021f4e84  (semantic: ResetIfLowHPRatio_021f4e84)
extern "C" ARM int func_ov024_021f4e84(int* p0, int id, int unused2, int* outFlag, void* out5) {
	struct CombatantStruct* c = GetCombatantWithFlag0x400ByID(*p0, id);
	if (!c) return 0;
	if (func_ov024_021db358(c) >= 0.5f) return 0;
	*outFlag = 0;
	memset(out5, -1, 0x10);
	return 1;
}
