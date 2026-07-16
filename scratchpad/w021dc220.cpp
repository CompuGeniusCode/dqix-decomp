#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetSlotPtr02160f20(void* obj);
int CheckSlotEntryKind021627fc(void* obj);
struct List021600f8;
void* GetNodeAtIndex021600f8(struct List021600f8* list, int index);
void ClearSubstructFlag0x4(unsigned char* obj);
int CheckSubstructFlag0x200(unsigned char* obj);
void SetSubstructByte0x6c(unsigned char* obj, unsigned char value);
extern "C" void func_02033920(void* a, int b, int c);

extern char data_ov025_021ef404[];
extern unsigned char data_ov025_021ef974;

struct Obj021dc220 {
    char pad0[0xe78];
    unsigned char field_e78;
    char pad1[0x33];
    int field_eac;
};

struct ListNode02160094_dc220 {
    char pad0[0x20];
    unsigned short id;
    char pad1[0xc];
    struct ListNode02160094_dc220* next;
};

struct List02160094_dc220 {
    char pad0[0x10];
    struct ListNode02160094_dc220* head;
};

// USA: func_ov025_021dc220
ARM void UpdateAndDispatchSlot_021dc220(void* obj) {
    struct Obj021dc220* self = (struct Obj021dc220*)obj;
    struct BattleStruct* battle = GetBattleStruct();
    void* slot = GetSlotPtr02160f20(obj);
    short idx = -1;

    if (CheckSlotEntryKind021627fc(obj)) {
        *(int*)(data_ov025_021ef404 + 4) = 1;
        self->field_eac = 6;
        {
            void* node8 = GetNodeAtIndex021600f8((struct List021600f8*)slot, 0);
            if (node8 != NULL) {
                idx = *(short*)((char*)node8 + 0xe);
            }
        }
    } else {
        self->field_eac = 3;
    }

    if (slot != NULL) {
        struct List02160094_dc220* list = (struct List02160094_dc220*)slot;
        struct ListNode02160094_dc220* node = list->head;
        int allowDefault = 1;
        while (node != NULL) {
            struct CombatantStruct* combatant = GetCombatantFromList(battle, node->id);
            if (combatant != NULL) {
                ClearSubstructFlag0x4((unsigned char*)combatant);
                if (idx >= 0) {
                    int allow = allowDefault;
                    if (CheckSubstructFlag0x200((unsigned char*)combatant)) {
                        allow = 0;
                    } else if (self->field_e78 == 0) {
                        allow = 0;
                    }
                    if (allow) {
                        if (data_ov025_021ef974 == 0) {
                            func_02033920(combatant, idx, 1);
                        } else {
                            SetSubstructByte0x6c((unsigned char*)combatant, idx);
                        }
                    }
                }
            }
            node = node->next;
        }
    }
}
