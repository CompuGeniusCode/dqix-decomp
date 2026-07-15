#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
void ClearSubstructByte0x56(unsigned char* obj);
void* GetActiveCombatWork(void);
int GetIntAt0xa4(unsigned char* obj);
void ClearBitIfValueFound02167434(unsigned char* obj, int value);

struct Obj021e697c {
    char pad[8];
    unsigned char field8;
};

// USA: func_ov025_021e697c
ARM int ClearFoundBitsForList_021e697c(struct Obj021e697c* obj, int p1, int unusedArg, void* p3) {
    int local[8];
    struct BattleStruct* bs = GetBattleStruct();
    int count = DispatchByIndex021820bc(p3, p1, obj->field8, (int)&local[0]);
    int i;
    for (i = 0; i < count; i++) {
        struct CombatantStruct* c = GetCombatantFromList(bs, local[i]);
        if (c != NULL) {
            ClearSubstructByte0x56((unsigned char*)c);
            {
                void* work = GetActiveCombatWork();
                int val = GetIntAt0xa4((unsigned char*)c);
                ClearBitIfValueFound02167434((unsigned char*)work, val);
            }
        }
    }
    return 1;
}
