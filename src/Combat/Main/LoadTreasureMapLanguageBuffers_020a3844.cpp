#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/FileIO.h"
#include "System/Memory.h"
#include "std_library_functions.h"

extern "C" int func_ov017_0218b5b0(void);
unsigned char* GetTreasureMapLanguageData(struct BattleStruct* battle);
void SetTreasureMapLanguageDataPtr(struct BattleStruct* battle, unsigned char* to);
void ReleaseBattleBuffers020a39d8(SafeAllocator* alloc);
void ShiftInBitOnGlobalObject(void);
void HalveGlobalObjectCounter(void);
extern "C" void func_020c9be0(void);

extern const char data_020f1a9c[];
extern const char data_020f1ab0[];

// USA: func_020a3844  (semantic: LoadTreasureMapLanguageBuffers_020a3844)
extern "C" ARM int func_020a3844(SafeAllocator* alloc) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int base = func_ov017_0218b5b0();
    unsigned char* word = GetTreasureMapLanguageData(battleStruct);
    if (word != 0 || *(void**)(base + 0x4000 + 0x48c) != 0) {
        ReleaseBattleBuffers020a39d8(alloc);
    }

    unsigned char* buf = (unsigned char*)alloc->Allocate(0x2000);
    unsigned char* buf2 = (unsigned char*)alloc->Allocate(0x44);
    *(unsigned char**)(base + 0x4000 + 0x48c) = buf2;

    unsigned int fileSize = 0;
    ShiftInBitOnGlobalObject();
    void* extracted = ExtractFileFromGP2(data_020f1a9c, data_020f1ab0, &fileSize);
    memcpy(buf, extracted, fileSize);
    if (fileSize > 0x2000) {
        func_020c9be0();
    }

    unsigned int srcOff = 0;
    unsigned int count = 0;
    VectorizedInvertedMemcpy(buf, &count, 4);
    srcOff += 4;

    for (unsigned int i = 0; i < count; i++) {
        unsigned char* base4000 = (unsigned char*)base + 0x4000;
        VectorizedInvertedMemcpy(buf + srcOff, *(unsigned char**)(base4000 + 0x48c) + i * 4, 4);
        srcOff += 4;
    }

    HalveGlobalObjectCounter();
    SetTreasureMapLanguageDataPtr(battleStruct, buf);
    return 1;
}
