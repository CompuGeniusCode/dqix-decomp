#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_ov017_021bd5d0(void);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

// USA: func_ov001_021609a0
ARM int Function_021609a0(void) {
	func_ov017_021bd5d0();
	struct BattleStruct* bs = GetBattleStruct();
	struct Obj020397cc* obj = (struct Obj020397cc*)GetCombatantAtField0x397c(bs);
	CancelPendingAction020397cc(obj, 1);
	return 1;
}
