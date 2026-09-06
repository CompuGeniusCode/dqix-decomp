#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct AngleTrig0202e9a4;
void DestroyTenAndOne_021e4f18(void*);
int GetFieldIfFlag4(char*);
void SetField0x238True(void*);
void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4*, int);

// USA: func_ov023_021fc6cc
ARM void ReinitEntriesAndAngle021fc6cc(void* obj) {
    for (int i = 0; i < 2; i++) {
        DestroyTenAndOne_021e4f18((char*)obj + 0x20 + i * 0xc20);
    }
    void* p = (void*)GetFieldIfFlag4((char*)GetBattleStruct());
    SetField0x238True(p);
    SetAngleAndTrigTable0202e9a4((struct AngleTrig0202e9a4*)p, *(int*)((char*)obj + 0x1000 + 0x860));
}
