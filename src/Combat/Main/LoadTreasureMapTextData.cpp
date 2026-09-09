#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/FileIO.h"
#include "System/Memory.h"
#include "std_library_functions.h"

extern "C" int func_ov017_0218b5b0(void);
unsigned char* GetTreasureMapLanguageData(struct BattleStruct* battle);
void SetTreasureMapLanguageDataPtr(struct BattleStruct* battle, unsigned char* to);
extern "C" void func_020a395c(void);
extern "C" int func_020a36cc(void** out, unsigned int idx);
extern "C" void FatalHalt(void);

extern const char strDataTmapTdataGp2[];
extern const char strTdataLgPac[];

// USA: LoadTreasureMapTextData
// The only file path in this function's literal pool is "tdata_<LG>.pac".
extern "C" ARM int LoadTreasureMapTextData(void) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int base = func_ov017_0218b5b0();
    unsigned char* buf = GetTreasureMapLanguageData(battleStruct);
    if (buf != 0 || *(void**)(base + 0x4000 + 0x48c) != 0) {
        func_020a395c();
    }

    if (!func_020a36cc((void**)&buf, 0x2000)) return 0;
    if (!func_020a36cc((void**)(base + 0x4000 + 0x48c), 0x44)) return 0;

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
    unsigned int i = 0;
    while (i < count) {
        VectorizedInvertedMemcpy(buf + srcOff, *(unsigned char**)((unsigned char*)base + 0x4000 + 0x48c) + i * 4, 4);
        srcOff += 4;
        ++i;
    }

    BackgroundLoader::RemoveLockGlobal();
    SetTreasureMapLanguageDataPtr(battleStruct, buf);
    return 1;
}
