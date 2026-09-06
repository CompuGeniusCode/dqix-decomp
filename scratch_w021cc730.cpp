#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150(unsigned char* obj);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cc730 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short idxLow3 : 3;
    unsigned short fieldB : 8;
    unsigned short idxNibble : 4;
    unsigned short flagBit : 1;
    unsigned short field6;
    int field8;
    unsigned char fieldc;
    unsigned char fieldd;
    unsigned char fielde;
    unsigned char pad2[5];
};

// USA: func_ov017_021cc730
ARM void EnqueueBitfieldEvent_021cc730(int index, int flag, int byteB, int byteC) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, index);
    if (!combatant) return;
    int field150 = GetFieldAt0x150((unsigned char*)combatant);
    if (!field150) return;

    void* p = GetData02100044();

    struct LocalEvt021cc730 evt;
    evt.idxLow3 = index;
    int idx = *(int*)((char*)field150 + 0x950);
    evt.tag = 0xa;
    evt.fieldB = *(unsigned short*)((char*)field150 + idx * 2 + 0x16c);
    evt.idxNibble = *(int*)((char*)field150 + 0x950);
    evt.field8 = *(int*)((char*)field150 + idx * 4 + 0x138);
    evt.field6 = *(unsigned short*)((char*)field150 + 0x564);
    evt.fieldc = *(unsigned char*)((char*)field150 + idx + 0x186);
    evt.flagBit = flag;
    evt.fieldd = byteB;
    evt.fielde = byteC;

    func_0205e330(p, &evt, 0);
}
