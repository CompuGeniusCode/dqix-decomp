#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct TagInfo_021d26a4 {
    unsigned char pad[4];
    unsigned char id;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
};

extern "C" int func_ov017_0218b5b0(void);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
void SetFlagBit_0218d4b8(unsigned char* base, int bit);
void ClearFlagBit_0218d4d0(void* obj, int bit);
extern "C" void func_ov017_02191aac(void* obj, int mode, int idx, unsigned char mask);

// USA: func_ov017_021d26a4  (semantic: SetCombatantField150FlagAndNotify)
extern "C" ARM void func_ov017_021d26a4(void* unused, TagInfo_021d26a4* info, struct BattleStruct* battleStruct, void* base) {
    int flagBase = func_ov017_0218b5b0();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battleStruct, info->id);
    if (combatant == 0) {
        return;
    }
    unsigned char* field150 = (unsigned char*)GetFieldAt0x150((unsigned char*)combatant);
    if (field150 == 0) {
        return;
    }
    bool bit0 = info->flag0;
    field150[0x56c] = bit0;
    if (field150[0x56c]) {
        func_ov017_02191aac(base, 1, info->id, 2);
    }
    if (info->flag1) {
        SetFlagBit_0218d4b8((unsigned char*)flagBase, info->id);
    } else {
        ClearFlagBit_0218d4d0((void*)flagBase, info->id);
    }
}
