#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"

extern "C" void func_020da244(void* p);
extern "C" void* func_02012fe4(void);
extern int data_ov017_021d82fc;

extern "C" void _Z29ClearSlotsAndProcess_021a27e8v(void* unused);
struct CombatantStruct* GetCombatantWithFlag0x20(struct BattleStruct* battleStruct, int combatantId);
void ResetAndUnlinkNode02037330(unsigned char* obj);

void* GetGlobalPtr021075f4(void);
struct Struct_0203cfb4;
void Init0203cfb4(struct Struct_0203cfb4* obj);

struct InitState0208f7ecStruct;
void InitState0208f7ec(struct InitState0208f7ecStruct* s);

struct PointerField32c_ffc0;
void* GetPointerAt0x32c(struct PointerField32c_ffc0* obj);
struct PointerField330_ffd0;
void* GetPointerAt0x330(struct PointerField330_ffd0* obj);

void ClearCombatantSlot(struct BattleStruct* battleStruct, int id);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);

// USA: func_ov017_021a316c  (semantic: TeardownOverlayState_021a316c)
extern "C" ARM void func_ov017_021a316c(unsigned char* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    unsigned char* globalPtr = (unsigned char*)func_02012fe4();
    int i;
    int j;
    int k;

    if (((SafeAllocator*)(obj + 0x11c0))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + 0x11c0))->Destroy();
        ((SafeAllocator*)(obj + 0x11c0))->ResetAllocatorPointer();
    }

    if (((SafeAllocator*)(obj + 0x113c))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + 0x113c))->Destroy();
        ((SafeAllocator*)(obj + 0x113c))->ResetAllocatorPointer();
    }

    if (((SafeAllocator*)(obj + 0x113c))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + 0x113c))->Destroy();
        ((SafeAllocator*)(obj + 0x113c))->ResetAllocatorPointer();
    }

    if (((SafeAllocator*)(obj + 0x1244))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + 0x1244))->Destroy();
        ((SafeAllocator*)(obj + 0x1244))->ResetAllocatorPointer();
    }

    func_020da244(&data_ov017_021d82fc);
    _Z29ClearSlotsAndProcess_021a27e8v(obj);

    for (i = 0; i < 0x30; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x20(battleStruct, i + 0x70);
        if (c) {
            ResetAndUnlinkNode02037330((unsigned char*)c);
        }
    }

    ((SafeAllocator*)(obj + 0xc4))->Reset();
    CopyInternalFields0207df50((struct Foo0207df50*)(obj + 0x5dc));

    for (j = 0; j < 0x30; j++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x20(battleStruct, j + 0x70);
        if (c) {
            ResetAndUnlinkNode02037330((unsigned char*)c);
        }
    }

    Init0203cfb4((struct Struct_0203cfb4*)GetGlobalPtr021075f4());
    InitState0208f7ec((struct InitState0208f7ecStruct*)(globalPtr + 0x2664));

    if (GetPointerAt0x32c((struct PointerField32c_ffc0*)battleStruct)) {
        ClearCombatantSlot(battleStruct, 0xc9);
    }
    if (GetPointerAt0x330((struct PointerField330_ffd0*)battleStruct)) {
        ClearCombatantSlot(battleStruct, 0xca);
    }

    for (k = 1; k < 4; k++) {
        if (GetCombatantUnchecked(battleStruct, k + 0xca)) {
            ClearCombatantSlot(battleStruct, k + 0xca);
        }
    }
    ClearCombatantSlot(battleStruct, 0xce);
}
