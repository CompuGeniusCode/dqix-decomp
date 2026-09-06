#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
int GetField0x3acValue(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantFromList(struct BattleStruct* battleStruct, int combatantId);
struct Obj02088818;
void SetStateAndByte0x6a(struct Obj02088818* obj, unsigned short mode);

struct StatBits021c6ebc {
    unsigned char pad00[0x22];
    unsigned short lo : 2;
    unsigned short mid : 4;
    unsigned short hi : 3;
};

struct SrcTag021c6ebc {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned char fielda;
    unsigned char padb;
    unsigned short fieldc;
    unsigned short fielde;
};

// USA: func_ov017_021c6ebc
ARM void ApplyStatBitsToCombatant_021c6ebc(int unused0, struct SrcTag021c6ebc* src, struct BattleStruct* battleStruct, unsigned char* base) {
    void* table = *(void**)(base + 0x3000 + 0x718);
    void* a = func_ov017_021b8478(table);
    if (a == 0) {
        return;
    }
    if (func_ov017_021b8468(table) == 0) {
        return;
    }
    if (GetField6b0_021b8470(table) == 0) {
        return;
    }
    if (*(signed char*)((char*)a + 0x2a) == GetField0x3acValue(battleStruct)) {
        return;
    }
    if (*(unsigned short*)((char*)a + 8) != src->field4) {
        return;
    }
    struct CombatantStruct* combatant = GetCombatantFromList(battleStruct, src->field6);
    if (combatant == 0) {
        return;
    }
    {
        struct StatBits021c6ebc* t = (struct StatBits021c6ebc*)combatant->currentStats;
        unsigned short v = src->field8;
        t->lo = v;
    }
    {
        struct StatBits021c6ebc* t = (struct StatBits021c6ebc*)combatant->currentStats;
        unsigned short v = src->field8 >> 2;
        t->mid = v;
    }
    {
        struct StatBits021c6ebc* t = (struct StatBits021c6ebc*)combatant->currentStats;
        unsigned short v = src->field8 >> 6;
        t->hi = v;
    }
    SetStateAndByte0x6a((struct Obj02088818*)combatant->currentStats, src->field8 >> 9);
    *((unsigned char*)combatant->currentStats + 0x24) = src->fielda;
    *(unsigned short*)((char*)combatant->currentStats + 0x4) = src->fieldc;
    *(unsigned short*)((char*)combatant->currentStats + 0x6) = src->fielde;
}
