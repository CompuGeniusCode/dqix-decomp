#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void ClearCombatantSlot(struct BattleStruct* battleStruct, int id);
void InitStruct02059cc8(unsigned char* obj);

struct MainBlock0205859c {
    int listHead;
    int listCount;
    unsigned char slots[0x10 * 0xd4];
    int current;
    void* tail;
    int pendingCount;
};

// USA: func_0205859c
ARM void ResetBattleEncounterState0205859c(struct MainBlock0205859c* self) {
    struct BattleStruct* bs = GetBattleStruct();
    int i, j;
    for (i = 0; i < 0x10; i++) {
        ClearCombatantSlot(bs, i + 0xd0);
    }
    for (j = 0; j < 0x10; j++) {
        InitStruct02059cc8(self->slots + j * 0xd4);
    }
    self->current = 0;
    if (self->tail != NULL) {
        *(int*)((char*)self->tail + 0x1ec) = 0;
        self->listCount = self->pendingCount;
    } else {
        self->listHead = 0;
        self->listCount = 0;
    }
}
