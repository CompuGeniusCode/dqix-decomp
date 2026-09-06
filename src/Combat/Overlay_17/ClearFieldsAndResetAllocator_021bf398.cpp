#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void SetByteField0x253(void* obj);
int GetFieldIfFlag4(char* obj);
void SetField0x23cTrue(void* obj);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern int data_02114e20;

struct List020727d8;
void ResetListHeader020727ec(struct List020727d8* list);

// USA: func_ov017_021bf398
ARM void ClearFieldsAndResetAllocator_021bf398(char* self) {
	struct BattleStruct* battle = GetBattleStruct();
	int flagResult = GetFieldIfFlag4((char*)battle);
	struct CombatantStruct* combatant = GetCombatantAtField0x397c(battle);
	SetField0x23cTrue((void*)flagResult);
	SetByteField0x253(combatant);
	SafeAllocator* allocator = (SafeAllocator*)(self + 0x14);
	void* p = allocator->GetSignedAllocator();
	if (p) {
		allocator->Reset();
		allocator->Destroy();
		ResetListHeader020727ec((struct List020727d8*)(self + 0xc));
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
	}
	self[1] = 1;
}
