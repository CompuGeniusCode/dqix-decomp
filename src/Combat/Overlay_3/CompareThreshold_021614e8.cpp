#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov003_02160c58(int id, short* out1, short* out2);

// USA: func_ov003_021614e8
ARM int CompareThreshold_021614e8(int id) {
    struct BattleStruct* bs = GetBattleStruct();
    unsigned char* p = (unsigned char*)GetPtrField0x2a04(bs);
    unsigned char a = p[0xf7c];
    unsigned char b = p[0x2000 + 0xc8c];
    short sum = (short)(a + b);
    short v = sum - 1;
    short out1, out2;
    func_ov003_02160c58(id, &out1, &out2);
    return out1 <= v;
}
