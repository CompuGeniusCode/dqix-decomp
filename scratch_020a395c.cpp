#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_020a0c0c(void);
unsigned char* GetTreasureMapLanguageData(struct BattleStruct* battle);
void SetTreasureMapLanguageDataPtr(struct BattleStruct* battle, unsigned char* to);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern AllocatorUnion data_02114e20;

// USA: func_020a395c
ARM void ReleaseBattleBuffersAlt020a395c(void) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int base = func_ov017_0218b5b0();
    unsigned char* word = GetTreasureMapLanguageData(battleStruct);
    TailForward02012da4(&data_02114e20, *(void**)(base + 0x4000 + 0x48c));
    TailForward02012da4(&data_02114e20, word);
    if (*(unsigned char*)(base + 0x4000 + 0x490) != 0) {
        func_020a0c0c();
        *(unsigned char*)(base + 0x4000 + 0x490) = 0;
    }
    SetTreasureMapLanguageDataPtr(battleStruct, 0);
    *(void**)(base + 0x4000 + 0x48c) = 0;
}
