#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" ARM int func_ov017_0218b5b0(void);
unsigned char* GetFieldAt0x150(unsigned char* obj);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);
void SetFlagBit_0218d4b8(unsigned char* base, int bit);
void ClearFlagBit_0218d4d0(void* obj, int bit);

struct Cfg021d26a4 {
    unsigned char pad[4];
    unsigned char id;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char restbits : 6;
};

// USA: func_ov017_021d26a4
extern "C" ARM void func_ov017_021d26a4(void* unused, struct Cfg021d26a4* cfg, struct BattleStruct* battleStruct, char* obj) {
    unsigned char* base = (unsigned char*)func_ov017_0218b5b0();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battleStruct, cfg->id);
    if (!combatant) return;
    unsigned char* field150 = GetFieldAt0x150((unsigned char*)combatant);
    if (!field150) return;

    int bit0 = cfg->bit0 ? 1 : 0;
    field150[0x56c] = bit0;
    if (bit0 & 0xff) {
        func_ov017_02191aac(obj, 1, cfg->id, 2);
    }

    if (cfg->bit1) {
        SetFlagBit_0218d4b8(base, cfg->id);
    } else {
        ClearFlagBit_0218d4d0(base, cfg->id);
    }
}
