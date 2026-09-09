#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/FileIO.h"
#include "System/Memory.h"
#include "std_library_functions.h"

extern "C" int func_ov017_0218b5b0(void);
unsigned char* GetTreasureMapLanguageData(struct BattleStruct* battle);
void SetTreasureMapLanguageDataPtr(struct BattleStruct* battle, unsigned char* to);
extern "C" void func_020a39d8(SafeAllocator* alloc);
extern "C" void FatalHalt(void);

extern const char strDataTmapTdataGp2[];
extern const char strTdataLgPac[];

// Loads the localized treasure-map text, tdata_<LG>.pac out of data/tmap/tdata.gp2, into a 0x2000
// buffer that becomes the battle struct's treasure-map language data. The file leads with a word
// count and that many words follow; they go into the 0x44 struct at +0x448c of ov017's block that
// Struct44C8.h names TreasureMapLanguageDataOffsets, whose seventeen words are named individually
// (bossIDsAndWeights, environs, prefixNames, localeNames, grottoBossDrops...). The read is bracketed
// by the BackgroundLoader global lock, and the 0x2000 overrun check calls FatalHalt only after
// the copy has already happened.
extern "C" ARM int LoadTreasureMapLanguageData(SafeAllocator* alloc) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int base = func_ov017_0218b5b0();
    unsigned char* word = GetTreasureMapLanguageData(battleStruct);
    if (word != 0 || *(void**)(base + 0x4000 + 0x48c) != 0) {
        func_020a39d8(alloc);
    }

    unsigned char* buf = (unsigned char*)alloc->Allocate(0x2000);
    unsigned char* buf2 = (unsigned char*)alloc->Allocate(0x44);
    *(unsigned char**)(base + 0x4000 + 0x48c) = buf2;

    unsigned int fileSize = 0;
    BackgroundLoader::AddLockGlobal();
    void* extracted = ExtractFileFromGP2(strDataTmapTdataGp2, strTdataLgPac, &fileSize);
    memcpy(buf, extracted, fileSize);
    if (fileSize > 0x2000) {
        FatalHalt();
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

    BackgroundLoader::RemoveLockGlobal();
    SetTreasureMapLanguageDataPtr(battleStruct, buf);
    return 1;
}
