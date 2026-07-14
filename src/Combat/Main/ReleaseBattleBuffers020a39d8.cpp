#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
unsigned char* GetTreasureMapLanguageData(struct BattleStruct* battle);
void SetTreasureMapLanguageDataPtr(struct BattleStruct* battle, unsigned char* to);

// USA: func_020a39d8
ARM void ReleaseBattleBuffers020a39d8(SafeAllocator* alloc) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int base = func_ov017_0218b5b0();
    int word = (int)GetTreasureMapLanguageData(battleStruct);
    alloc->Free(*(void**)(base + 0x4000 + 0x48c));
    alloc->Free((void*)word);
    SetTreasureMapLanguageDataPtr(battleStruct, 0);
    *(void**)(base + 0x4000 + 0x48c) = NULL;
}
