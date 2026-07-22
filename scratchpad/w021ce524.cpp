#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);

struct Sub0x134_021ce524 {
    unsigned char pad0[0x809];
    unsigned char f809;
    unsigned char f80a;
    unsigned char pad1[1];
    unsigned char f80c;
    unsigned char f80d;
    unsigned char f80e;
    unsigned char pad2[1];
    unsigned char f810;
};

struct LocalEvt021ce524 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4;
    unsigned char byte2;
    unsigned char byte3;
    unsigned char byte4;
    unsigned char byte5;
    unsigned char byte6;
    unsigned char byte7;
    unsigned char pad2[0x14 - 0xc];
};

// USA: func_ov017_021ce524
ARM void EnqueueField150DataEvent_021ce524(int combatantId) {
    void* p = GetData02100044();
    LocalEvt021ce524 buf;
    buf.tag = 0x29;
    *(unsigned short*)((unsigned char*)&buf.field4) = combatantId;
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantWithFlag0x100(battleStruct, combatantId);
    if (!c) return;
    unsigned char* field150 = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
    if (!field150) return;
    unsigned char* dst = (unsigned char*)&buf.field4;
    struct Sub0x134_021ce524* s = (struct Sub0x134_021ce524*)(field150 + 0x134);
    dst[2] = s->f809;
    dst[3] = s->f80a;
    dst[4] = s->f80c;
    dst[5] = s->f80d;
    dst[6] = s->f80e;
    dst[7] = s->f810;
    func_0205e330(p, &buf, 0);
}
