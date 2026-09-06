#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" int func_ov024_021fe698(void* obj, int arg);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int unused, int val);

struct Obj_021fcfa0 {
    char pad0[4];
    short field4;
    unsigned char field6;
    struct CombatantStruct* field8;
    int fieldC;
};

struct BuffWord_021fcfa0 {
    signed int attackBuff : 3;
    signed int defenseBuff : 3;
    signed int agilityBuff : 3;
    signed int charmBuff : 3;
    signed int magicalMightBuff : 3;
    signed int magicalMendingBuff : 3;
    signed int unkBuff18 : 3;
    signed int unkBuff21 : 3;
};

// USA: func_ov024_021fcfa0  (semantic: CheckBuffsAndDispatch_021fcfa0)
extern "C" ARM void func_ov024_021fcfa0(struct Obj_021fcfa0* obj) {
    int count;
    int flag = 0;
    if (obj->field6 == 2) flag = 1;
    if (obj->field6 == 0) return;
    if (obj->fieldC >= 3) flag = 1;
    if (!flag) return;
    if (!func_ov024_021fe698(obj, 0x12)) return;
    count = 0;
    if (((struct BuffWord_021fcfa0*)((char*)obj->field8->currentStats + 0x58))->defenseBuff >= 2) count++;
    if (((struct BuffWord_021fcfa0*)((char*)obj->field8->currentStats + 0x58))->unkBuff21 >= 2) count++;
    if (((struct BuffWord_021fcfa0*)((char*)obj->field8->currentStats + 0x58))->attackBuff >= 2) count++;
    if (count >= 2) return;
    char buf[0xc8];
    memset(buf, 0, 0xc8);
    *(float*)(buf + 0xc4) = 1000.0f;
    func_ov024_021f9874(obj, buf, 0, obj->field4 & 0xff);
}
