#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

extern "C" void* GetZoneState(void);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_0218d510(int a, void* b);
extern "C" void* func_02012d88(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;
extern "C" int func_020100a8(struct BattleStruct* battleStruct);
struct Holder020159c0;
extern "C" void func_020159c0(struct Holder020159c0* holder, int key);
extern char strDataAniDChrNumSpr_021d7bf8[];

// Queues /data/ani/d_<letter><nnn>.spr from this object's own category letter at +0x17 and number
// at +0x14; that it is an item sprite comes from the siblings SetUpItemIconSprite and
// QueueItemIconSpriteLoad, which build the same name out of an itemdt record, not from anything here.
// The ROM has 1021 of these files over nine letters (i 240, w 175, b 159, m 130, r 89, p 77, g 63,
// c 53, s 35). The id 0x5617 at +0x12 takes the other branch, a 0x4000-byte scratch heap instead
// of a sprite, and what that id names is not established; the 3 it returns is a caller step code.
extern "C" ARM int BeginItemSpriteLoad(char* self) {
    if (*(unsigned short*)(self + 0x12) == 0x5617) {
        self[0x54] = 1;
        ((SafeAllocator*)(self + 0x58))->ResetAllocatorPointer();
        ((SafeAllocator*)(self + 0x58))->CreateTypeA(func_02012d88(&data_02114e20, 0x4000), 0x4000);
        ((SafeAllocator*)(self + 0x58))->Reset();
        func_ov017_0218d510(func_ov017_0218b5b0(), self + 0x58);
    } else {
        struct BattleStruct* battle = GetBattleStruct();
        void* holder = GetZoneState();
        func_020159c0((struct Holder020159c0*)holder, (signed char)func_020100a8(battle));
        char buf[0x80];
        sprintf(buf, strDataAniDChrNumSpr_021d7bf8, *(signed char*)(self + 0x17), *(signed short*)(self + 0x14));
        *(int*)(self + 0x28) = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
    }
    return 3;
}
