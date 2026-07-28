#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150(unsigned char* obj);

struct Obj0203c108;
void SwapGlobalEntry0203c108(struct Obj0203c108* obj, char* fmt);

extern "C" void func_ov000_0216fe9c(void* obj);

int GetField0x3acValue(struct BattleStruct* battleStruct);

// USA: func_ov000_02171138
extern "C" ARM void func_ov000_02171138(void* objRaw) {
    char* obj = (char*)objRaw;
    int combatantId = *(int*)(obj + 0x4c);
    if (combatantId < 0) {
        return;
    }
    struct BattleStruct* bs = GetBattleStruct();
    combatantId = *(int*)(obj + 0x4c);
    struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, combatantId);
    if (!c) {
        return;
    }
    char* field150 = (char*)(int)GetFieldAt0x150((unsigned char*)c);
    if (!field150) {
        return;
    }
    int off134 = *(int*)((char*)c + 0x134);
    SwapGlobalEntry0203c108((struct Obj0203c108*)(obj + 0x68), (char*)off134);
    *(int*)(obj + 0x5c) = 2;
    int idx950 = *(int*)(field150 + 0x950);
    *(unsigned char*)(obj + 0x440) = (unsigned char)idx950;
    idx950 = *(int*)(field150 + 0x950);
    char* p = field150 + idx950 * 2 + 0x100;
    unsigned short val = *(unsigned short*)(p + 0x6c);
    *(unsigned char*)(obj + 0x43f) = (unsigned char)val;

    short savedC = *(short*)(obj + 0xc);
    short saved8 = *(short*)(obj + 0x8);
    short savedE = *(short*)(obj + 0xe);
    short savedA = *(short*)(obj + 0xa);
    func_ov000_0216fe9c(obj + 8);
    *(short*)(obj + 0xc) = savedC;
    *(short*)(obj + 0x8) = saved8;
    *(short*)(obj + 0xe) = savedE;
    *(short*)(obj + 0xa) = savedA;

    *(int*)(obj + 0x28) = *(int*)(field150 + 0xa8);
    *(unsigned char*)(obj + 0x1c) = 0;
    *(unsigned short*)(obj + 0x82) = 0;
    *(unsigned short*)(obj + 0x84) = 0;
    *(unsigned char*)(obj + 0x86) = 0;
    int fieldVal = GetField0x3acValue(bs);
    if (*(int*)(obj + 0x4c) == fieldVal) {
        *(unsigned char*)(obj + 0x24) |= 2;
    }
    *(unsigned char*)(obj + 0x24) &= ~1;
}
