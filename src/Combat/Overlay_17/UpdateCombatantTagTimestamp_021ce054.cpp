#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150(unsigned char* obj);
unsigned long long GetCurrentTimestamp(void);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);

struct Src021ce054 {
    unsigned char pad0[4];
    unsigned short field4;
    short field6;
    unsigned short field8;
};

// USA: func_ov017_021ce054  (semantic: UpdateCombatantTagTimestamp_021ce054)
extern "C" ARM void func_ov017_021ce054(int checkVal, struct Src021ce054* src, struct BattleStruct* battleStruct, char* obj) {
    int inRange = (checkVal >= 0) && (checkVal <= 3);
    if (!inRange) return;
    struct CombatantStruct* c = GetCombatantWithFlag0x100(battleStruct, src->field8);
    if (!c) return;
    unsigned char* p = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
    void* g = func_0202ae18();
    if (src->field4 != 1) return;
    if (src->field6 > 0) {
        func_ov017_02191aac(obj, 1, *(short*)((char*)c + 4), 2);
        p[0x56c] = 1;
        if (func_0202c540(g)) return;
        unsigned long long ts = GetCurrentTimestamp();
        *(unsigned int*)(p + 0x480) = (unsigned int)ts;
        *(unsigned int*)(p + 0x484) = (unsigned int)(ts >> 32);
    } else {
        p[0x56c] = 0;
        func_ov017_02191aac(obj, 0, *(short*)((char*)c + 4), 2);
    }
}
