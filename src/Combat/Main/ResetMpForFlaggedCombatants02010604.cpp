#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
extern "C" void* func_0205ec34(void);
extern "C" void func_ov017_021d2400(void);
extern "C" void func_02048150(void* combatant, int a, int b);
extern "C" void func_ov017_021cedf4(int a, int b, int c);
extern "C" void func_ov017_021c9e00(int a, int b, int c, int d);
extern "C" void func_ov017_0219bfb4(int a, int b);

int CheckField0NonZero(int* obj);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

struct Combatant020482bc;
int RestoreMaxMpToFull(struct Combatant020482bc* c);

struct Bytes02033b88;
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);

void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);

extern int data_020f83d8;

struct CombatantView02010604 {
    char pad0[0x130];
    unsigned int* current;
    char pad130[0x18c - 0x134];
    unsigned int field18c;
};

// USA: func_02010604
ARM void ResetMpForFlaggedCombatants02010604(struct BattleStruct* obj, int arg1, int arg2, int arg3) {
    void* g = func_0202ae18();
    int i;

    if (arg1 != 0) {
        if (CheckField0NonZero((int*)g)) {
            func_ov017_021d2400();
        }
    }

    for (i = 0; i < *((unsigned char*)((char*)obj + 0x3000) + 0x980); i++) {
        int id = *((unsigned char*)((char*)obj + i + 0x3000) + 0x97c);
        struct CombatantStruct* combatant = GetCombatantWithFlag0x800(obj, id);
        struct CombatantView02010604* view;
        if (combatant == NULL) continue;
        view = (struct CombatantView02010604*)combatant;
        if ((*view->current & 1) == 0) continue;
        func_02048150(combatant, 0, 1);
        RestoreMaxMpToFull((struct Combatant020482bc*)combatant);
        view->field18c &= ~1;
        SetByte0xbeShiftPrev((struct Bytes02033b88*)combatant, 0);
        if (CheckField0NonZero((int*)g)) {
            func_ov017_021cedf4(id, 1, 0);
            func_ov017_021c9e00(id, 0, 0, 1);
        }
    }

    if (arg2 != 0) {
        unsigned int* p970 = (unsigned int*)((char*)obj + 0x3000 + 0x970);
        *p970 = *p970 >> 1;
    }

    func_ov017_0219bfb4(2, arg3);

    if (*(int*)((char*)obj + 0x5000 + 0xcb0) == 0x10 && *(int*)((char*)obj + 0x5000 + 0xcb4) == 2 &&
        *(int*)((char*)obj + 0x5000 + 0xcb8) == 1) {
        void* g2 = func_0205ec34();
        SetOrClearBitInArray(g2, (unsigned char*)((char*)g2 + 0x8c), 0x113a, 0);
    }

    *((unsigned char*)&data_020f83d8 + 0x729) = 0;
}
