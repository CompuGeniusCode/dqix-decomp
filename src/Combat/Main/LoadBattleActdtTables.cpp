#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "Combat/Main/BattleList.h"

extern "C" {
    void __clear(void*, unsigned int);
    extern "C" int GetLanguage(BattleStruct*);
    void func_02079a58(void*, void*, void*, void*, unsigned int, unsigned int);
    void func_02079bac(void*, void*, void*, void*, unsigned int, unsigned int);
}

struct Obj02079808;
extern "C" void* func_02079a3c(void* obj);
extern "C" int func_02079808(void* base, struct Obj02079808* obj);

extern unsigned char fileStagingBuffer[0x30000];
extern const char strDataPrmActdtBGp2[];
extern const char strActdtBLgNat[];
extern const char strActdamageBNat[];

// USA: LoadBattleActdtTables
// The file paths in this function's literal pool are "data/prm/actdt_b.gp2", "actdt_b_<LG>.nat" and
// "actdamage_b.nat".
#pragma opt_propagation off
// Reads the battle-side actdt tables out of data/prm/actdt_b.gp2: the localized actdt_b_<LG>.nat into
// obj+0xc and actdamage_b.nat into obj+0x24. func_02079900 is the same function over the _a files.
// The split looks like battle against field, because this one is only ever called from ov000 and the
// _a one only from ov017. What "actdt" abbreviates is not established -- prm carries actname.nat,
// actmsg.gp2 and actexp.gp2 next to it, so "action data" is a suspicion and no more. Both unpacks go
// to the same fileStagingBuffer address, so func_02079a58 consumes the actdt table before the second.
extern "C" ARM void LoadBattleActdtTables(void* obj, void* a1, unsigned int a2) {
    unsigned int len;
    unsigned char* base;
    base = fileStagingBuffer;
    unsigned int capacity = sizeof(fileStagingBuffer);
    GPCReadPair pair;
    func_02079a3c(&pair);

    unsigned int sizeOut;

    const char* name = strDataPrmActdtBGp2;
    bool ok = LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine,
        name, base, sizeOut, capacity, false, NULL);
    if (ok) {
        unsigned int outSize2 = 0;
        len = sizeOut;
        capacity -= len;
        BattleStruct* battle = GetBattleStruct();
        char buf[0x20];
        __clear(buf, sizeof(buf));

        int language = GetLanguage(battle);
        StringReplaceLanguageTag(strActdtBLgNat, buf, language);

        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, base + len,
            outSize2, capacity, buf);

        func_02079a58((char*)obj + 0xc, a1, base + len,
            (void*)func_02079808, 0, a2);

        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, base + len,
            outSize2, capacity, strActdamageBNat);

        func_02079bac((char*)obj + 0x24, a1, base + len, NULL, 0, 0);
    }

    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
