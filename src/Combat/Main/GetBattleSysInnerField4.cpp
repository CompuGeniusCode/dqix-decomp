#include <globaldefs.h>

struct BattleSysInner020d06d4 {
    int field0;      // 0x0
    int field4;      // 0x4
    char pad8[0x14]; // 0x8
    int field1c;     // 0x1c
};

extern BattleSysInner020d06d4* data_021118e0;

// USA: func_020d06d4
ARM int GetBattleSysInnerField4() {
    return data_021118e0->field4;
}
