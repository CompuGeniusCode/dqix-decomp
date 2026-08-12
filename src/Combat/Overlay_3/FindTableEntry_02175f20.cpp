#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

unsigned char GetTableByte0207ca94(int index);
int FindNthPositiveShort0207c6b8(unsigned char* obj, unsigned int index, int target);

// USA: func_ov003_02175f20  (semantic: FindTableEntry_02175f20)
#pragma opt_propagation off
extern "C" ARM int func_ov003_02175f20(void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    void* p = GetPtrField0x2a04(bs);
    short v1 = *(short*)((char*)obj + 0x1012);
    int idx = (short)(v1 - 286);
    unsigned char cnt = GetTableByte0207ca94(idx);
    short v3 = *(short*)((char*)obj + 0x100e);
    short v2 = *(short*)((char*)obj + 0x1014);
    unsigned char* argPtr = (unsigned char*)p + 0x1d4;
    short idx2 = v2 * 5 + (short)(v3 - 295);
    return FindNthPositiveShort0207c6b8(argPtr, cnt, idx2);
}
