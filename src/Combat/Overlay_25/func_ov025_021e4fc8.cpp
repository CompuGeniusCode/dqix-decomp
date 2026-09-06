#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_02057924(void);
void* GetInlineRecordByBattleId(void* obj, int id);
void* GetSlotPtr_021e8cf0_021e8cf0(char* base, int idx);
void ClearCombatantSlot(struct BattleStruct* battleStruct, int id);
void InitStruct02059cc8(unsigned char* obj);
extern int data_ov025_021ef988;

struct Param021e4fc8 { char pad[8]; unsigned char field8; };

// USA: func_ov025_021e4fc8  (semantic: ClearSlotAndInitRecord_021e4fc8)
extern "C" ARM int func_ov025_021e4fc8(struct Param021e4fc8* p) {
    void* slot = GetSlotPtr_021e8cf0_021e8cf0(*(char**)((char*)&data_ov025_021ef988 + 0xc), p->field8);
    if (slot) {
        struct BattleStruct* bs = GetBattleStruct();
        ClearCombatantSlot(bs, *(int*)slot);
        void* obj = func_02057924();
        void* record = GetInlineRecordByBattleId(obj, *(int*)slot);
        if (record) {
            InitStruct02059cc8((unsigned char*)record);
        }
    }
    return 1;
}
