#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
void RemoveMatchingNodes02037364(void* obj, int key);
void ShiftField0x1cInto0x20(void* obj, unsigned int v);
void* GetActiveCombatWork(void);
void SetField0x3b0Value(struct BattleStruct* battleStruct, int value);
void ResetAndUnlinkNode02037330(unsigned char* obj);
void ClearCombatantSlot(struct BattleStruct* battleStruct, int id);
int GetField0x3b0Value(struct BattleStruct* battleStruct);

extern "C" int func_02057924(struct BattleStruct* battleStruct);
extern "C" void func_02036e34(void* combatant, char* buf, unsigned char b);
extern "C" void func_02057f00(int a, unsigned short b);
extern "C" int func_ov000_02160f14(void* work);

struct QueueNode021e8bc4 {
    unsigned char selector;
    unsigned char threshold;
    unsigned short id;
    unsigned short key;
    char pad0[2];
    struct QueueNode021e8bc4* next;
};

struct CombatantExtra021e8bc4 {
    char pad0[0x14];
    char* name;
    char pad1[0x19 - 0x14 - 4];
    unsigned char flags19;
    char pad2[0x1c - 0x19 - 1];
    unsigned int field1c;
};

struct SelfObj021e8bc4 {
    char pad0[0x1d8];
    struct QueueNode021e8bc4* queue;
};

// USA: func_ov025_021e8bc4
ARM void ProcessQueueUpToCap_021e8bc4(void* obj, int cap) {
    struct SelfObj021e8bc4* self = (struct SelfObj021e8bc4*)obj;
    char buffer[0x28];

    if (self->queue != NULL) {
        struct BattleStruct* battle = GetBattleStruct();
        int misc = func_02057924(battle);
        struct QueueNode021e8bc4* node;
        GetField0x3b0Value(battle);
        node = self->queue;

        while (node != NULL && cap <= node->threshold) {
            switch (node->selector) {
            case 0: {
                struct CombatantExtra021e8bc4* combatant = (struct CombatantExtra021e8bc4*)GetCombatantUnchecked(battle, node->id);
                if (combatant != NULL) {
                    if (combatant->name != NULL) {
                        strcpy(buffer, combatant->name);
                    }
                    {
                        unsigned char flags19 = combatant->flags19;
                        unsigned int oldField1c = combatant->field1c;
                        RemoveMatchingNodes02037364(combatant, node->key);
                        func_02036e34(combatant, buffer, flags19);
                        ShiftField0x1cInto0x20(combatant, oldField1c);
                    }
                }
                break;
            }
            case 1:
                func_02057f00(misc, node->key);
                break;
            case 2:
                break;
            case 3:
                SetField0x3b0Value(battle, func_ov000_02160f14(GetActiveCombatWork()));
                break;
            case 4: {
                struct CombatantExtra021e8bc4* combatant = (struct CombatantExtra021e8bc4*)GetCombatantUnchecked(battle, node->id);
                if (combatant != NULL) {
                    ResetAndUnlinkNode02037330((unsigned char*)combatant);
                    ClearCombatantSlot(battle, node->id);
                }
                break;
            }
            }
            node = node->next;
        }

        self->queue = node;
    }
}
