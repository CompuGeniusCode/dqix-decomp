#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov017_021d612c(void*);
extern int AbsPlus159IfNegative0215ad2c(int x);
extern SafeAllocator* data_ov001_021658b8[8];
void* GetFieldPtrAt0x5ca4(void* obj);
int GetField0x3b0Value(struct BattleStruct* battleStruct);
void SetField0x3b0Value(struct BattleStruct* battleStruct, int value);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

struct Obj0204a120;
void InitState0204a120(struct Obj0204a120* obj);

struct Owner0204a3f0;
struct Holder0204a3f0;
void SetHolderAndMarkNode0204a3f0(struct Owner0204a3f0* owner, struct Holder0204a3f0* h);

void SetName0204a440(char* obj, const char* src);
void SetStringField0234(char* obj, const char* src);
void SetStringField0244(char* obj, const char* src);

struct S0204a5dc;
void SetField0x220(struct S0204a5dc* p, int v);

void SetBitsInField0x6c(unsigned char* obj, unsigned int mask);

// USA: func_ov001_02160768  (semantic: AllocateAndInitStateNode_02160768)
extern "C" ARM int func_ov001_02160768(char* self) {
	struct BattleStruct* bs = GetBattleStruct();
	SafeAllocator* allocator = data_ov001_021658b8[0];
	void* fieldPtr = GetFieldPtrAt0x5ca4(bs);

	int a = func_ov017_021d60f4(self);
	void* name = func_ov017_021d612c(self + 0x8);
	void* str1 = func_ov017_021d612c(self + 0x10);
	void* str2 = func_ov017_021d612c(self + 0x18);
	int b = func_ov017_021d60f4(self + 0x20);

	int id1 = AbsPlus159IfNegative0215ad2c(a);
	int id2 = AbsPlus159IfNegative0215ad2c(b);

	struct CombatantStruct* combatant1 = GetCombatantUnchecked(bs, id1);
	if (combatant1 == NULL) return 0;

	struct CombatantStruct* combatant2 = GetCombatantUnchecked(bs, id2);
	if (combatant2 == NULL) return 0;

	void* newObj = allocator->Allocate(0x268);

	*(int*)((char*)fieldPtr + 0x4) = GetField0x3b0Value(bs);

	InitState0204a120((struct Obj0204a120*)newObj);
	SetHolderAndMarkNode0204a3f0((struct Owner0204a3f0*)newObj, (struct Holder0204a3f0*)combatant1);
	SetName0204a440((char*)newObj, (const char*)name);
	SetStringField0234((char*)newObj, (const char*)str1);
	SetStringField0244((char*)newObj, (const char*)str2);
	SetField0x220((struct S0204a5dc*)newObj, (int)combatant2);

	SetBitsInField0x6c((unsigned char*)combatant1, 1);
	SetBitsInField0x6c((unsigned char*)combatant1, 0x20);

	SetField0x3b0Value(bs, (int)newObj);
	return 1;
}
