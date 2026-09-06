#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void);
void* GetData02153637(void);

struct Entry020e3054 { unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3; };
struct Container020e34bc { struct Entry020e3054 entries[8]; unsigned char flags[8]; };
int GetEntryStatusForKey020e34bc(struct Container020e34bc* obj, int key);

extern "C" void func_ov017_021bd5d0(void);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
void Dispatch020e3428(void* a, int b);
void ClearEntryIfCurrentArrMatches020e3468(struct Entry020e3054* list, int key);
void StoreInFirstEmptySlot(unsigned char* base, unsigned char val);

struct Self02155ca8 {
	char pad0[0xa];
	unsigned short field_a;
	char pad1[0xf8 - 0xc];
	unsigned int flags : 27;
	unsigned int other : 5;
};

struct Obj02154de4;
int ProcessAndDispatchState_02154de4(struct Obj02154de4* self);

// USA: func_ov001_02155ca8
ARM int DispatchEntryStatus_02155ca8(struct Self02155ca8* self) {
	struct BattleStruct* bs = GetBattleStruct();
	func_0202ae18();
	if ((self->flags & 0x10) && func_0202c508() != 0) {
		void* container = GetData02153637();
		int status = GetEntryStatusForKey020e34bc((struct Container020e34bc*)container, 1);
		if (status == 1) {
			func_ov017_021bd5d0();
			struct CombatantStruct* combatant = GetCombatantAtField0x397c(bs);
			CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
			Dispatch020e3428(container, 1);
		} else if ((unsigned int)(status - 3) > 2) {
			return self->field_a;
		} else {
			ClearEntryIfCurrentArrMatches020e3468((struct Entry020e3054*)container, 1);
			StoreInFirstEmptySlot((unsigned char*)container, 1);
			return self->field_a;
		}
	}
	return ProcessAndDispatchState_02154de4((struct Obj02154de4*)self);
}
