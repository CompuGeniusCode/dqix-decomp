#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0205ec34(void);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
extern "C" int func_020321e0(void* a, void* b, short c, void* d, int e);
int LookupAndForEachNode020649b0(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);

struct ListNode02198e30 {
    unsigned short field0;
    short field2;
    char pad4[0xc];
    int field10;
    char pad14[0x18];
    struct ListNode02198e30* next;
};

struct LocalScratch_02198e30 {
    char pad0[4];
    int fieldC;
    char pad1[0x28];
    int field30;
};

// USA: func_ov017_02198e30
ARM void SyncListNodeAndNotify_02198e30(unsigned char* baseParam) {
    struct BattleStruct* bs = GetBattleStruct();
    void* g = func_0205ec34();
    struct ListNode02198e30* node = *(struct ListNode02198e30**)((char*)g + 0x494);
    struct CombatantStruct* c = GetCombatantAtField0x397c(bs);

    while (node != 0) {
        if (func_020321e0((char*)c + 0x44, (char*)node + 0x14, node->field2, (char*)node + 4, node->field10) != 0) {
            break;
        }
        node = node->next;
    }

    signed char byte491 = *(signed char*)((char*)g + 0x491);
    if (node == 0) {
        if (byte491 > -1) {
            struct LocalScratch_02198e30 local;
            local.fieldC = byte491;
            if (LookupAndForEachNode020649b0(g, 5, &local)) {
                func_0206f81c(&local);
            }
        }
        *(unsigned char*)((char*)g + 0x491) = 0xff;
        return;
    }

    if (node->field0 == byte491) return;

    if (byte491 > -1) {
        struct LocalScratch_02198e30 local;
        local.fieldC = byte491;
        if (LookupAndForEachNode020649b0(g, 5, &local)) {
            func_0206f81c(&local);
        }
        local.fieldC = -1;
        local.field30 = 0;
    }

    *(unsigned char*)(baseParam + 0x4446) = (unsigned char)node->field0;

    struct LocalScratch_02198e30 local2;
    local2.fieldC = node->field0;
    if (LookupAndForEachNode020649b0(g, 2, &local2)) {
        func_0206f81c(&local2);
    }

    unsigned short fval = node->field0;
    void* g2 = func_0205ec34();
    *(unsigned char*)((char*)g2 + 0x491) = (unsigned char)fval;
}
