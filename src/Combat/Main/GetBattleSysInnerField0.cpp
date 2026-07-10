#include <globaldefs.h>

struct BattleSysInner020cffb8 {
    int field0;      // 0x0
    int field4;      // 0x4
    char pad8[0x14]; // 0x8
    int field1c;     // 0x1c
};

extern BattleSysInner020cffb8* data_021118e0;

// USA: func_020cffb8
ARM int GetBattleSysInnerField0() {
    return data_021118e0->field0;
}
