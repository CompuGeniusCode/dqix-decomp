#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
void* GetData02100044(void);
extern "C" void* func_0202ae18(void);
struct BitArrayObj0205e830;
int TestBitInArray0x1524(struct BitArrayObj0205e830* obj, int index);
struct QNode0205e1e4;
struct QNode0205e1e4* PopAndRequeueNode(void* obj, int* outPtr);

typedef void (*Fn021d48f0)(int, struct QNode0205e1e4*, struct BattleStruct*, int, void*);
extern Fn021d48f0 data_ov017_021d7f98[];

// USA: func_ov017_021d48f0
ARM void ProcessQueuedNodes_021d48f0(void) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int base = func_ov017_0218b5b0();
    void* data = GetData02100044();
    void* search = func_0202ae18();
    int outVal;
    struct QNode0205e1e4* node;
    while ((node = PopAndRequeueNode(data, &outVal)) != 0) {
        unsigned char typeId = *(unsigned char*)node;
        if (typeId >= 0xbc) continue;
        if (!TestBitInArray0x1524((struct BitArrayObj0205e830*)data, typeId)) continue;
        data_ov017_021d7f98[typeId](outVal, node, battleStruct, base, search);
    }
}
