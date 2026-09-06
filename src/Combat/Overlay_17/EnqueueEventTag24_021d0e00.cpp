#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetData02100044(void);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021d0e00 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char id;
    unsigned char val;
    unsigned char pad1[14];
};

// USA: func_ov017_021d0e00  (semantic: EnqueueEventTag24_021d0e00)
extern "C" ARM void func_ov017_021d0e00(int id) {
    void* p = GetData02100044();
    struct LocalEvt021d0e00 buf;
    buf.tag = 0x18;
    unsigned char* dst = &buf.id;

    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantWithFlag0x800(bs, id);
    if (!c) return;
    int field150 = GetFieldAt0x150((unsigned char*)c);
    if (!field150) return;

    dst[0] = (unsigned char)id;
    dst[1] = *(unsigned char*)((char*)field150 + 0x56a);
    func_0205e330(p, &buf, 0);
}
