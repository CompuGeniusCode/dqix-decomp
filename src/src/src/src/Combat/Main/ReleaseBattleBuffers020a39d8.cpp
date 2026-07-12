#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
int GetWord0x63e0(void* obj);
void SetWord0x63e0(void* obj, int value);

// USA: func_020a39d8
ARM void ReleaseBattleBuffers020a39d8(SafeAllocator* alloc) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int base = func_ov017_0218b5b0();
    int word = GetWord0x63e0(battleStruct);
    alloc->Free(*(void**)(base + 0x4000 + 0x48c));
    alloc->Free((void*)word);
    SetWord0x63e0(battleStruct, 0);
    *(void**)(base + 0x4000 + 0x48c) = NULL;
}
