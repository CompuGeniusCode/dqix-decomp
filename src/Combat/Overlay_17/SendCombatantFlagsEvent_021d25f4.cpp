#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
void* GetData02100044(void);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
int HasFlagBit_0218d4ec(void* obj, int bit);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d25f4 {
    unsigned char field0;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char restBits : 6;
    unsigned char pad2[0xe];
};

struct EventBuf021d25f4 {
    unsigned char tag;
    unsigned char pad[3];
    struct Sub021d25f4 sub;
};

// USA: func_ov017_021d25f4  (semantic: SendCombatantFlagsEvent_021d25f4)
extern "C" ARM void func_ov017_021d25f4(int combatantId) {
    int handle = func_ov017_0218b5b0();
    void* p = GetData02100044();
    struct EventBuf021d25f4 buf;
    buf.tag = 0x20;
    struct Sub021d25f4* sub = &buf.sub;

    struct BattleStruct* battle = GetBattleStruct();
    if (battle == 0) return;
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battle, combatantId);
    if (combatant == 0) return;
    int val = GetFieldAt0x150((unsigned char*)combatant);
    if (val == 0) return;

    sub->field0 = (unsigned char)combatantId;
    sub->flag0 = *(unsigned char*)((char*)val + 0x56c);
    int hasFlag = HasFlagBit_0218d4ec((void*)handle, combatantId);
    sub->flag1 = (hasFlag != 0);

    func_0205e330(p, &buf, 0);
}
