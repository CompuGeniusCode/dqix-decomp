#include <globaldefs.h>

struct BattleStruct;
struct BattleStruct* GetBattleStruct();
struct CombatantStruct;
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

extern "C" void func_ov017_021a5568(void* p);
extern "C" void _Z19InsertNodeAfterHeadP12List02046a3cP12Node02046a3c(void* list, void* node);

// USA: func_ov017_021a5530
ARM void CancelActionAndInsertNode_021a5530(char* self) {
	CancelPendingAction020397cc((struct Obj020397cc*)GetCombatantAtField0x397c(GetBattleStruct()), 1);
	func_ov017_021a5568(*(void**)(self + 0x3000 + 0x71c));
	void* list = *(void**)(self + 0x3000 + 0x6fc);
	_Z19InsertNodeAfterHeadP12List02046a3cP12Node02046a3c(list, *(void**)(self + 0x3000 + 0x71c));
}
