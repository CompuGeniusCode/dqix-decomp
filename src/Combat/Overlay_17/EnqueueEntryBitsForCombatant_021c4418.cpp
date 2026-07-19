#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct BattleStruct;
struct BattleStruct* GetBattleStruct();
void* GetData02100044(void);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
struct Field150Holder02052e2c;
short* GetField150Ptr0x488_02052e2c(struct Field150Holder02052e2c* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Entry150_021c4418 {
    char pad[0x14];
    unsigned char bit0 : 1;
    unsigned char bits1_3 : 3;
    unsigned char bits4_7 : 4;
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    short f16;
    short f18;
    short f1a;
};

struct LocalEvt021c4418 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
    unsigned char field7;
    unsigned char field8;
    unsigned char pad9;
    short fieldA;
    short fieldC;
    short fieldE;
    signed char field10;
};

// USA: func_ov017_021c4418  (semantic: EnqueueEntryBitsForCombatant_021c4418)
extern "C" ARM void func_ov017_021c4418(int combatantId, signed char flag10) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    void* p = GetData02100044();
    struct CombatantStruct* c = GetCombatantWithFlag0x100(battleStruct, combatantId);
    if (!c) return;
    struct Entry150_021c4418* entry = (struct Entry150_021c4418*)GetField150Ptr0x488_02052e2c((struct Field150Holder02052e2c*)c);
    if (!entry) return;

    struct LocalEvt021c4418 evt;
    evt.tag = 1;
    evt.field4 = combatantId;
    evt.field5 = entry->lowNibble;
    evt.field6 = entry->bits4_7;
    evt.field7 = entry->bits1_3;
    evt.field8 = entry->bit0;
    evt.fieldA = entry->f16;
    evt.fieldC = entry->f18;
    evt.fieldE = entry->f1a;
    evt.field10 = flag10;
    func_0205e330(p, &evt, 0);
}
