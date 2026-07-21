#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
int GetGlobalField0x1c020421a0();
int GetField0x3acValue(struct BattleStruct* battleStruct);
void SetBitInField0x34(unsigned char* obj, int index);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
void* GetDataPtr02114e04_020d6c00(void);
void ClearFlags020466f4(unsigned int* word, unsigned int mask);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
void CancelPendingAction020397cc(void* obj, int arg1);
void EnqueueEventTag127ForParty_021c3f70(unsigned short tag);
void EnqueueEventTag122_021c8b78(unsigned short param);
extern "C" void func_ov017_021c9c64(unsigned short a, int b);
extern "C" void func_020c9be0(void);

// USA: func_ov017_021b848c
ARM void TryDispatchCombatantAction_021b848c(unsigned char* obj, signed char* actionFlags, int idx, int val, unsigned short arg4, signed char arg5, int arg6, int arg7) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    GetGlobalField0x1c020421a0();
    if (*(unsigned short*)(obj + 0x6b4) == 4 || *(unsigned short*)(obj + 0x6b4) == 6 || *(unsigned short*)(obj + 0x6b4) == 0) {
        return;
    }
    if (actionFlags[GetField0x3acValue(battleStruct)] == 0) {
        return;
    }

    if (idx >= 0 && idx <= 3 && actionFlags[idx] != 0 && GetCombatantUnchecked(battleStruct, idx) != 0) {
        void* dataPtr = GetDataPtr02114e04_020d6c00();
        ClearFlags020466f4((unsigned int*)dataPtr, 0x200);
        OrBitsIntoField0((unsigned int*)dataPtr, 0x40000);
        struct CombatantStruct* c = GetCombatantAtField0x397c(battleStruct);
        if (c) {
            CancelPendingAction020397cc(c, 1);
            *(unsigned short*)((char*)c + 0xb2) = 0;
        }

        if (actionFlags[0] != 0 && GetCombatantUnchecked(battleStruct, 0) != 0) {
            SetBitInField0x34(obj + 0x1c, 0);
        }
        if (actionFlags[1] != 0 && GetCombatantUnchecked(battleStruct, 1) != 0) {
            SetBitInField0x34(obj + 0x1c, 1);
        }
        if (actionFlags[2] != 0 && GetCombatantUnchecked(battleStruct, 2) != 0) {
            SetBitInField0x34(obj + 0x1c, 2);
        }
        if (actionFlags[3] != 0 && GetCombatantUnchecked(battleStruct, 3) != 0) {
            SetBitInField0x34(obj + 0x1c, 3);
        }

        if (!TestBitAt0x34(obj + 0x1c, (unsigned char)idx)) {
            func_020c9be0();
        }
        obj[0x46] = idx;

        if (val == 0) {
            GetField0x3acValue(battleStruct);
        }
        *(int*)(obj + 0x48) = val;
        *(unsigned short*)(obj + 0x1e) = arg4;
        if (arg7 >= 0) {
            *(int*)(obj + 0x28) = arg7;
        }
        if (arg5 > -1) {
            obj[0x51] = (unsigned char)arg5;
            void* ptr = *(void**)(obj + 0x6b0);
            if (ptr) {
                *(unsigned char*)((char*)ptr + 0x8000 + 0xe49) = (unsigned char)arg5;
            }
        }

        EnqueueEventTag127ForParty_021c3f70(*(unsigned short*)(obj + 0x24));
        if (idx != GetField0x3acValue(battleStruct)) {
            if (arg6 != 0) {
                obj[0x6c6] = 1;
            }
            *(int*)(obj + 0x6b8) = 0;
            *(unsigned short*)(obj + 0x6b4) = 4;
        } else {
            *(unsigned short*)(obj + 0x6b4) = 6;
        }
        return;
    }

    func_ov017_021c9c64(*(unsigned short*)(obj + 0x24), 0);
    EnqueueEventTag122_021c8b78(*(unsigned short*)(obj + 0x24));
    *(unsigned short*)(obj + 0x6b4) = 5;
}
