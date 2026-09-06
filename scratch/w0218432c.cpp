#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct DeepField_0218432c {
    unsigned int unk0 : 9;
    signed int val : 10;
    unsigned int unk1 : 13;
};
struct Layer5400_0218432c { char pad[4]; struct DeepField_0218432c field; };
struct Layer29c_0218432c { char pad[0x5400]; struct Layer5400_0218432c l2; };
struct Outer_0218432c { char pad[0x29c]; struct Layer29c_0218432c l1; };

struct Range_0218432c { short lo; short pad; };

extern struct Range_0218432c data_ov012_0218afaa[];
extern struct Range_0218432c data_ov012_0218afac[];

// USA: func_ov012_0218432c
ARM int GetSpeedRangeOffset_0218432c(int index) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int scaled = ((struct Outer_0218432c*)battleStruct)->l1.l2.field.val;
    int result;
    if (data_ov012_0218afaa[index].lo > scaled) {
        result = 0;
    } else if (scaled >= data_ov012_0218afac[index].lo) {
        result = 0;
    } else {
        result = scaled - data_ov012_0218afaa[index].lo;
    }
    return result;
}
