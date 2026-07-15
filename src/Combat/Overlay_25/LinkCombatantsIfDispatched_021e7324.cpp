#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct ListNode020378dc;
void UnlinkOrClearListNode020378dc(struct ListNode020378dc* node);
struct Node02037890;
void AttachNodeWithLabel02037890(struct Node02037890* node, struct Node02037890* src, char* str);

struct In021e7324 {
    char pad[8];
    unsigned char idx1;
    unsigned char idx2;
    char pad2[2];
    char* label;
};

struct DispatchOut021e7324 {
    int id;
    char pad[0x2c];
};

// USA: func_ov025_021e7324
ARM int LinkCombatantsIfDispatched_021e7324(struct In021e7324* a, int b, int unused, void* obj) {
    struct DispatchOut021e7324 out1;
    struct DispatchOut021e7324 out2;
    int r1 = DispatchByIndex021820bc(obj, b, a->idx1, (int)&out1.id);
    int r2 = DispatchByIndex021820bc(obj, b, a->idx2, (int)&out2.id);
    if (!r1 || !r2) {
        return 1;
    }
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c1 = GetCombatantUnchecked(bs, out1.id);
    struct CombatantStruct* c2 = GetCombatantUnchecked(bs, out2.id);
    if (!c1 || !c2) {
        return 1;
    }
    UnlinkOrClearListNode020378dc((struct ListNode020378dc*)c1);
    AttachNodeWithLabel02037890((struct Node02037890*)c1, (struct Node02037890*)c2, a->label);
    return 1;
}
