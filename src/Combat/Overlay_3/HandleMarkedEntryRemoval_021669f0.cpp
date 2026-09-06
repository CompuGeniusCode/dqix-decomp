#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPtrField0x2a04(struct BattleStruct*);
extern "C" int func_ov003_02166a90(char* self, int val);

struct FindEntryContainer02086a04;
int RemoveOrShiftMarkedEntry02086a04(struct FindEntryContainer02086a04* c, int id);

extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);

struct CombatantStruct;
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

// USA: func_ov003_021669f0  (semantic: HandleMarkedEntryRemoval_021669f0)
extern "C" ARM int func_ov003_021669f0(char* self) {
	struct BattleStruct* bs;
	void* p2a04;
	int r;
	struct CombatantStruct* c;

	if (*(short*)(self + 0x480) < 0) return 1;

	bs = GetBattleStruct();
	p2a04 = GetPtrField0x2a04(bs);
	r = func_ov003_02166a90(self, *(short*)(self + 0x480));
	if (r == 0) return 0;
	if (r == 1) {
		RemoveOrShiftMarkedEntry02086a04((struct FindEntryContainer02086a04*)p2a04, (signed char)*(short*)(self + 0x480));
		void* p = func_0205ec34();
		SetOrClearBitInArray(p, (unsigned char*)p + 0x8c, 0x784, 1);
	}

	c = GetCombatantAtField0x3ac(bs);
	if (c != NULL) {
		CancelPendingAction020397cc((struct Obj020397cc*)c, 1);
	}
	return 1;
}
