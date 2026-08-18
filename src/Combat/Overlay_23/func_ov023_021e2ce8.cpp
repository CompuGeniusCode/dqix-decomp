#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "System/Cache.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" int func_ov017_0218b5b0(void);
extern "C" int func_ov017_021bdbcc(void* obj);
ARM void* GetTableEntry020421b0(int idx);
extern "C" int _Z32TransferMainObjCharData_020c5a28iij(int, int, unsigned int);

// USA: func_ov023_021e2ce8
extern "C" ARM void func_ov023_021e2ce8(int combatantId, void* p1) {
    if (combatantId < 0) return;

    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(bs, combatantId);
    if (p1 != 0 && combatant != 0) {
        void* p40 = *(void**)((char*)p1 + 0x40);
        void* entry = 0;
        if (p40 != 0) {
            unsigned short f4e = *(unsigned short*)((char*)p1 + 0x4e);
            if (f4e > 15) entry = (char*)p40 + 0x258;
        }

        if (entry != 0) {
            void* ref = *(void**)((char*)entry + 8);
            if (ref != 0) {
                void* p150 = *(void**)((char*)combatant + 0x150);
                int val950 = *(int*)((char*)p150 + 0x950);

                int flagB = func_ov017_0218b5b0();
                int chk = func_ov017_021bdbcc((void*)flagB);
                if (chk != 0) val950 = 0;

                unsigned short f4 = *(unsigned short*)((char*)ref + 0x4);
                int tableIdx = (val950 * 4 + 0x28) & 0xff;
                unsigned short masked = f4 & 0x3ff;
                int sizeAccum = masked << 5;

                int i;
                for (i = 0; i < 4; i++) {
                    void* tableEntry = GetTableEntry020421b0(tableIdx);
                    CleanInvalidateCacheRange(tableEntry, 0x20);
                    _Z32TransferMainObjCharData_020c5a28iij((int)tableEntry, sizeAccum, 0x20);
                    CleanCacheRange(tableEntry, 0x20);
                    tableIdx = (tableIdx + 1) & 0xff;
                    sizeAccum += 0x20;
                }
            }
        }
    }
}
