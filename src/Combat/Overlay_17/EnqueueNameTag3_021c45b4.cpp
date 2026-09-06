#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

void* GetData02100044(void);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
void* ResetBuffer02052a10(char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021c45b4 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char field4;
    char name[15];
};

// USA: func_ov017_021c45b4
ARM void EnqueueNameTag3_021c45b4(int combatantId) {
    struct BattleStruct* bs = GetBattleStruct();
    void* p = GetData02100044();
    struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, combatantId);
    if (!c) return;

    struct LocalEvt021c45b4 buf;
    buf.tag = 3;
    buf.field4 = (unsigned char)combatantId;
    char* rb = (char*)ResetBuffer02052a10((char*)c);
    strcpy(buf.name, rb);
    func_0205e330(p, &buf, 0);
}
