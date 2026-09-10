#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

extern "C" void* GetZoneState(void);
struct ZoneSlot;
extern "C" struct ZoneSlot* GetZoneRecordTable(void);
struct ZoneSlot {
	unsigned short zoneId;
	unsigned short flags;
	unsigned char unknown4[0xc];
	SafeAllocator* allocator;
	unsigned char unknown14[0x2f8];
	unsigned char buffers[0xc];
};
extern "C" struct ZoneSlot* func_02028bac(struct ZoneSlot* base, int index);
struct ZoneSlot;
extern "C" void func_020289c4(struct ZoneSlot* slot);
extern "C" void AllocatorUnionFreeVeneer(AllocatorUnion* alloc, void* data);
extern "C" void* AllocateRoundedToWord(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020a8e88(void* p);
extern "C" void ClearCombatantSlot(struct BattleStruct* battleStruct, int combatantId);
// Passed a trailing source-length argument that func_020a8e9c ignores, so the mangled
// name is spelled out instead of being re-derived from this declaration.
extern "C" void func_020a8e9c(
	void* buffers, SafeAllocator* allocator, void* src, unsigned int srcSize);

extern AllocatorUnion data_02114e20;
extern const char strDataPrmMonModdataNat[];
extern unsigned char fileStagingBuffer[0x30000];
#pragma opt_propagation off

// Tears the four zone slots down, releasing their allocators, clears combatant slots 0x70 through
// 0x9f, then turns slot 0 into a 0xa000 arena stamped 3 and deserializes data/prm/mon_moddata.nat
// into it. That file is 438 records of 0x40 bytes, the same 438 count as mon_btldata.nat, so it is
// indexed by monster species; what "moddata" abbreviates is not established. The caller only comes
// here when the slot already carries 3, so this is a reload. The halfword at +0 that carries it is
// the key FindZoneSlotById searches this same four-entry 0x318-byte table by and GetZoneRecordTable
// reads as a zone id, which is why it is spelled that way here; that a monster-data arena should
// sit under zone id 3 is not otherwise corroborated. The two loops line up: FindZoneSlotById puts a
// slot's twelve combatants at 0x70 + slot * 12, so 0x70 through 0x9f is all four slots' combatants.
extern "C" ARM void ResetAndLoadMonModData(void) {
	struct BattleStruct* battle = GetBattleStruct();
	GetZoneState();
	struct ZoneSlot* zoneSlots = GetZoneRecordTable();
	for (int slotIndex = 0; slotIndex < 4; slotIndex++) {
		struct ZoneSlot* slot = func_02028bac((struct ZoneSlot*)zoneSlots, slotIndex);
		func_020289c4((struct ZoneSlot*)slot);
		void* signedAlloc = (void*)slot->allocator->GetSignedAllocator();
		if (signedAlloc) {
			slot->allocator->Destroy();
			AllocatorUnionFreeVeneer(&data_02114e20, signedAlloc);
		}
	}
	for (int combatantId = 0x70; combatantId <= 0x9f; combatantId++) {
		ClearCombatantSlot(battle, combatantId);
	}
	struct ZoneSlot* slot0 = func_02028bac((struct ZoneSlot*)zoneSlots, 0);
	unsigned int size = 0xa000;
	slot0->flags |= 4;
	slot0->zoneId = 3;
	void* buffer = AllocateRoundedToWord(&data_02114e20, size);
	slot0->allocator->CreateTypeA(buffer, size);
	if (slot0 == NULL) return;
	func_020a8e88(slot0->buffers);
	BackgroundLoader::AddLockGlobal();
	unsigned int fileSize;
	if (LoadFileIntoMemory(strDataPrmMonModdataNat, fileStagingBuffer, &fileSize) != NULL) {
		func_020a8e9c(
			slot0->buffers, slot0->allocator, fileStagingBuffer, fileSize);
	}
	BackgroundLoader::RemoveLockGlobal();
}
