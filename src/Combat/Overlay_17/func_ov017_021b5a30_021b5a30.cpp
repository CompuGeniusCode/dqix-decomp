#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
void ResetFieldWithLog_0218d5c8(unsigned char* obj);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void SetByteField0x253(void* obj);
int GetFieldIfFlag4(char* obj);
void SetField0x238True(void* obj);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

extern int data_02114e20;

struct Obj021b5a30 {
	char pad0[0x40];
	SafeAllocator allocator1;
	unsigned char field0x54;
	char pad1[0x58 - 0x55];
	SafeAllocator allocator2;
};

// USA: func_ov017_021b5a30
extern "C" ARM void func_ov017_021b5a30(struct Obj021b5a30* self) {
	int base = func_ov017_0218b5b0();
	if (self->field0x54 != 0 && base != 0) {
		ResetFieldWithLog_0218d5c8((unsigned char*)base);
		self->field0x54 = 0;
	}

	void* p1 = self->allocator1.GetSignedAllocator();
	if (p1 != NULL) {
		self->allocator1.Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p1);
	}

	void* p2 = self->allocator2.GetSignedAllocator();
	if (p2 != NULL) {
		self->allocator2.Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p2);
	}

	struct BattleStruct* battle = GetBattleStruct();
	struct CombatantStruct* c = GetCombatantAtField0x397c(battle);
	if (c != NULL) {
		SetByteField0x253(c);
	}

	int flagField = GetFieldIfFlag4((char*)battle);
	if (flagField != 0) {
		SetField0x238True((void*)flagField);
	}

	if (base != 0) {
		ClearBitsInField4((unsigned int*)base, 0x80);
	}
}
