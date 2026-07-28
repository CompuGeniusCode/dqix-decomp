#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Node0216e8f0 {
    char pad[0xc];
    unsigned char field0xc;
};

struct Obj_02184ad8;
void SetField1c8True_02184ad8(struct Obj_02184ad8* obj);
void SetByte0x7f70(void* obj, unsigned char value);
extern "C" void* func_ov011_021849c8(void* a);
extern "C" Node0216e8f0* func_ov023_021f6880(void* obj, int key);
int ScaleStatsIfType12_021f6f10(void* self);

extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216e8f0  (semantic: SyncFlagAndNotify_0216e8f0)
extern "C" ARM int func_ov004_0216e8f0(void* obj) {
    void* p = func_ov011_021849c8(obj);
    if (p) {
        Node0216e8f0* node = func_ov023_021f6880(p, *(unsigned short*)(data_ov004_02171034 + 0xa));
        if (node) {
            node->field0xc &= ~0x10;
        }
    }
    SetField1c8True_02184ad8((struct Obj_02184ad8*)obj);
    struct BattleStruct* bs = GetBattleStruct();
    if (data_ov004_02171034[3] != 6) {
        Node0216e8f0* node2 = func_ov023_021f6880(p, 1);
        if (node2 && ScaleStatsIfType12_021f6f10(node2) == 0xb) {
            node2->field0xc &= ~0x8;
            SetByte0x7f70(bs, 1);
        }
    }
    return 0;
}
