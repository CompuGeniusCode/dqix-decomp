#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetActiveCombatWork(void);
int GetField0x3b4Value(struct BattleStruct* battleStruct);

struct Reset021e3158 { int a; int b; int c; int d; int e; int f; };
void ResetStruct_021e3158(struct Reset021e3158* p);

extern int data_ov025_021ef988;
extern struct Reset021e3158 data_ov025_021ef9a8;

struct S021e30e8 { char pad[8]; unsigned int field8; unsigned char field0xc; };

// USA: func_ov025_021e30e8  (semantic: CheckThresholdAndReset_021e30e8)
extern "C" ARM int func_ov025_021e30e8(struct S021e30e8* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    if (obj->field8 <= *(unsigned int*)((char*)&data_ov025_021ef988 + 0x34)) {
        if (obj->field0xc != 0) {
            void* work = GetActiveCombatWork();
            *(int*)((char*)work + 0x6fd0) = obj->field8;
        }
        ResetStruct_021e3158(&data_ov025_021ef9a8);
        return 1;
    }
    int* p = &data_ov025_021ef988 + 13;
    *p += GetField0x3b4Value(battle);
    return 0;
}
