#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "System/Cache.h"
#include "std_library_functions.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" int func_ov017_0218b5b0(void);
extern "C" int func_ov017_021bdbcc(void* obj);
ARM void* GetTableEntry020421b0(int idx);
extern "C" int _Z32TransferMainObjCharData_020c5a28iij(int, int, unsigned int);

// USA: func_ov002_021619b4
extern "C" ARM void func_ov002_021619b4(int combatantId, void* p1, void* dst) {
    if (combatantId < 0) return;

    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(bs, combatantId);
    if (p1 == 0 || dst == 0 || combatant == 0) return;

    void* p40 = *(void**)((char*)p1 + 0x40);
    void* entry = 0;
    if (p40 != 0) {
        unsigned short f4e = *(unsigned short*)((char*)p1 + 0x4e);
        if (f4e > 0x2a) entry = (char*)p40 + 0x690;
    }

    void* ref;
    if (entry == 0 || (ref = *(void**)((char*)entry + 8)) == 0) return;

    void* p150 = *(void**)((char*)combatant + 0x150);
    int val950 = *(int*)((char*)p150 + 0x950);

    int flagB = func_ov017_0218b5b0();
    int chk = func_ov017_021bdbcc((void*)flagB);
    if (chk != 0) val950 = 0;

    int tableIdx = (val950 * 4 + 0x28) & 0xff;
    void* tableEntry = GetTableEntry020421b0(tableIdx);
    memcpy(dst, tableEntry, 0x80);

    unsigned short f4 = *(unsigned short*)((char*)ref + 4);
    unsigned short masked = f4 & 0x3ff;
    int sizeAccum = masked << 5;

    CleanInvalidateCacheRange(dst, 0x80);
    _Z32TransferMainObjCharData_020c5a28iij((int)dst, sizeAccum, 0x80);
    CleanCacheRange(dst, 0x80);
}
