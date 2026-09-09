#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

extern "C" void* GetZoneState(void);
struct Entry_02028bd0;
extern "C" struct Entry_02028bd0* GetZoneRecordTable(void);
struct Element0x318_02028bac {
	unsigned short kind;
	unsigned short flags;
	unsigned char unk4[0xc];
	SafeAllocator* allocator;
	unsigned char unk14[0x2f8];
	unsigned char buffers[0xc];
};
extern "C" struct Element0x318_02028bac* func_02028bac(struct Element0x318_02028bac* base, int index);
struct BigRecord020289c4;
extern "C" void func_020289c4(struct BigRecord020289c4* obj);
extern "C" void AllocatorUnionFreeVeneer(AllocatorUnion* alloc, void* data);
extern "C" void* AllocateRoundedToWord(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020a8e88(void* p);
extern "C" void ClearCombatantSlot(struct BattleStruct* battleStruct, int id);
// Passed a trailing source-length argument that func_020a8e9c ignores, so the mangled
// name is spelled out instead of being re-derived from this declaration.
extern "C" void func_020a8e9c(
	void* obj, SafeAllocator* allocator, void* src, unsigned int srcSize);

extern AllocatorUnion data_02114e20;
extern const char strDataPrmMonModdataNat[];
extern unsigned char fileStagingBuffer[0x30000];
#pragma opt_propagation off

// Tears the four entry-table slots down, releasing their allocators, clears combatant slots 0x70
// through 0x9f, then turns slot 0 into a 0xa000 arena of kind 3 and deserializes
// data/prm/mon_moddata.nat into it. That file is 438 records of 0x40 bytes, the same 438 count as
// mon_btldata.nat, so it is indexed by monster species; what "moddata" abbreviates is not
// established. The caller only comes here when the slot is already kind 3, so this is a reload.
extern "C" ARM void ResetAndLoadMonModData(void) {
	struct BattleStruct* battle = GetBattleStruct();
	GetZoneState();
	struct Entry_02028bd0* entryTable = GetZoneRecordTable();
	for (int i = 0; i < 4; i++) {
		struct Element0x318_02028bac* elem = func_02028bac((struct Element0x318_02028bac*)entryTable, i);
		func_020289c4((struct BigRecord020289c4*)elem);
		void* signedAlloc = (void*)elem->allocator->GetSignedAllocator();
		if (signedAlloc) {
			elem->allocator->Destroy();
			AllocatorUnionFreeVeneer(&data_02114e20, signedAlloc);
		}
	}
	for (int id = 0x70; id <= 0x9f; id++) {
		ClearCombatantSlot(battle, id);
	}
	struct Element0x318_02028bac* elem0 = func_02028bac((struct Element0x318_02028bac*)entryTable, 0);
	unsigned int size = 0xa000;
	elem0->flags |= 4;
	elem0->kind = 3;
	void* buffer = AllocateRoundedToWord(&data_02114e20, size);
	elem0->allocator->CreateTypeA(buffer, size);
	if (elem0 == NULL) return;
	func_020a8e88(elem0->buffers);
	BackgroundLoader::AddLockGlobal();
	unsigned int fileSize;
	if (LoadFileIntoMemory(strDataPrmMonModdataNat, fileStagingBuffer, &fileSize) != NULL) {
		func_020a8e9c(
			elem0->buffers, elem0->allocator, fileStagingBuffer, fileSize);
	}
	BackgroundLoader::RemoveLockGlobal();
}
