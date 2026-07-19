#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x1000(struct BattleStruct* battleStruct, int combatantId);
void SetField0x2d0(void* obj, unsigned char value);
void SetField0x2d1(void* obj, unsigned char value);
void SetByte0x1c8(unsigned char* obj, unsigned char value);
void SetByte0x1c9(unsigned char* obj, unsigned char value);

struct LocalEvt021ce3ac {
    unsigned char pad0[4];
    unsigned short field4;
    signed char field6;
    signed char field7;
    signed char field8;
    signed char field9;
    unsigned char fielda;
};

// USA: func_ov017_021ce3ac
ARM void ApplyEventTag38Fields_021ce3ac(int unused0, LocalEvt021ce3ac* evt, struct BattleStruct* battleStruct) {
    struct CombatantStruct* c = GetCombatantWithFlag0x1000(battleStruct, evt->field4);
    if (c == NULL) {
        return;
    }
    ((void (*)(void*, int))SetField0x2d0)(c, evt->field6);
    ((void (*)(void*, int))SetField0x2d1)(c, evt->field7);
    ((void (*)(void*, int))SetByte0x1c8)(c, evt->field8);
    ((void (*)(void*, int))SetByte0x1c9)(c, evt->field9);
    *((unsigned char*)c + 0x2d2) = evt->fielda;
}
