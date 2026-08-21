#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetData02100044(void);
int GetFieldAt0x150(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct SubBuf021cff8c {
    int id;
    unsigned char idx;
    unsigned char count;
    short arr[4];
};

struct EventBuf021cff8c {
    unsigned char tag;
    unsigned char pad0[3];
    struct SubBuf021cff8c sub;
};

// USA: func_ov017_021cff8c
extern "C" ARM void func_ov017_021cff8c(int id, int skipCheck) {
    void* mgr = GetData02100044();
    struct BattleStruct* battle = GetBattleStruct();
    unsigned char* list = (unsigned char*)GetPtrField0x2a04(battle);

    int found = 0;
    if (skipCheck) {
        found = 1;
    } else {
        int i;
        for (i = 0; i < list[0xf7c]; i++) {
            unsigned char* row = list + i;
            if (id == row[0xf78]) { found = 1; break; }
        }
    }
    if (!found) return;

    struct CombatantStruct* c = GetCombatantWithFlag0x100(battle, id);
    if (!c) return;

    int field150 = GetFieldAt0x150((unsigned char*)c);
    if (!field150) return;

    short* src = (short*)(field150 + 0x454);

    struct EventBuf021cff8c buf;
    struct SubBuf021cff8c* r6 = &buf.sub;
    buf.tag = 0xa8;
    r6->id = id;
    r6->count = 4;
    r6->idx = 0;
    int i;
    for (i = 0; i < r6->count; i++) {
        r6->arr[i] = src[r6->idx + i];
    }
    func_0205e330(mgr, &buf, 0);

    unsigned char cnt2 = r6->count;
    int j = 0;
    r6->idx = cnt2;
    for (; j < r6->count; j++) {
        r6->arr[j] = src[r6->idx + j];
    }
    func_0205e330(mgr, &buf, 0);
}
