#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

extern "C" int func_ov017_0218b5b0(void);
extern "C" struct CombatantStruct* GetPlayerCombatant(struct BattleStruct* battleStruct);
extern "C" int GetCameraIfFlag4(char* obj);
extern "C" unsigned int func_0203b4d0(unsigned int* obj);
struct Obj020397cc;
extern "C" void StopCombatantMovement(struct Obj020397cc* obj, int arg1);
extern "C" void SetCameraFlags(unsigned char* obj, unsigned char mask);
extern "C" void func_020a27b8(unsigned char* obj);
extern "C" int IsListEmpty(void** obj);
extern "C" void func_0203b4a0(unsigned int* obj, unsigned int mask);
extern "C" void ReleaseROMFileTablesForAllocation(unsigned int);
extern "C" void* AllocateRoundedToWord(AllocatorUnion* alloc, unsigned int size);
extern "C" void FatalHalt(void);
extern "C" void SetBothScreensBrightness(void* obj, int value, int frames);
struct ResetObj020d7a5c;
extern "C" struct ResetObj020d7a5c* GetPendingMessageQueue();
struct Obj020d7aa0;
extern "C" void ClearPendingMessageQueue(struct Obj020d7aa0* obj);

extern int data_02114e20;
extern char strDataMenuStr;

struct MenuScreenFlags {
    unsigned int unknownBits0 : 4;
    unsigned int unknownBit4 : 1;
    unsigned int unknownBits5 : 27;
};

struct MenuScreenTask {
    char unknown0[0x8];
    int field8;
    int fieldc;
    SafeAllocator allocator;   // 0x10
    char name[0x14];           // 0x24
    struct MenuScreenFlags flags;  // 0x38
    char unknown3c[0x2];
    unsigned char field3e;     // 0x3e
    unsigned int field40;      // 0x40
    void* field44;             // 0x44
};

// Slot 0 of the four-entry table at 0x021d79e0, whose slot 3 (func_ov017_021b2758) undoes what
// this sets: the 0x244 flag, the ov017 state bits and the allocator. It reserves a 0x2f800 arena
// out of data_02114e20 and queues data/menu/<menuFileName> into it; the name is written by
// func_ov017_021b2ba0, which aborts on anything twelve characters or longer, so it is one of the
// short data/menu entries such as status.stb or memory2.stb.
// While the menu is up the field is held still: the combatant at BattleStruct+0x397c has its
// pending action cancelled and bit 1 of the field object's 0x244 is forced on, the previous
// value of that bit being saved here so slot 3 can put it back. Which menu is opened is a
// runtime value, so what the screen shows is not established.
extern "C" ARM int OpenMenuScreen(struct MenuScreenTask* menuTask) {
    struct BattleStruct* battle = (struct BattleStruct*)GetBattleStruct();
    int gameMainState = func_ov017_0218b5b0();
    unsigned char* fieldObject;
    struct CombatantStruct* combatant = GetPlayerCombatant(battle);
    fieldObject = (unsigned char*)GetCameraIfFlag4((char*)battle);
    int loader = (int)BackgroundLoader::GetInstance();
    void** menuSlot = *(void***)((char*)gameMainState + 0x3700);
    unsigned int currentStateBits = func_0203b4d0((unsigned int*)gameMainState);
    menuTask->field40 = currentStateBits;

    if (combatant) {
        StopCombatantMovement((struct Obj020397cc*)combatant, 1);
    }

    if (fieldObject) {
        menuTask->field3e = (fieldObject[0x244] & 2) != 0;
        SetCameraFlags(fieldObject, 2);
        func_020a27b8(fieldObject);
        menuTask->field44 = fieldObject;
    }

    if (!IsListEmpty(menuSlot)) {
        return menuTask->field8;
    }

    func_0203b4a0((unsigned int*)gameMainState, 0x10);
    ReleaseROMFileTablesForAllocation(0x2f800);
    void* menuArena = AllocateRoundedToWord((AllocatorUnion*)&data_02114e20, 0x2f800);
    if (!menuArena) {
        FatalHalt();
    }
    menuTask->allocator.CreateTypeA(menuArena, 0x2f800);

    char menuPath[0x50];
    sprintf(menuPath, &strDataMenuStr, menuTask->name);
    menuTask->fieldc = ((BackgroundLoader*)(loader))->QueueLoadFile((const char*)((int)menuPath), (SafeAllocator*)((int)&menuTask->allocator));

    if (!menuTask->flags.unknownBit4) {
        SetBothScreensBrightness((void*)gameMainState, -16, 30);
    }

    ClearPendingMessageQueue((struct Obj020d7aa0*)GetPendingMessageQueue());
    return 1;
}
