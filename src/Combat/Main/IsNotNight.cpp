#include <globaldefs.h>

struct S_020103b4 {
    char unk[0x3dc];
    int field3dc;
};

// BattleStruct+0x3dc holds the TimeOfDay enum and TimeOfDay_Night is 0, so this asks whether it is
// anything but night; TimeOfDay_Invalid, -1, also reads as not night. func_02010288 writes the field
// by running the day clock at +0x3cc through the same threshold ladder as the hand-written
// ConvertToTimeOfDay in LightingManager, and func_02010364 can pin it to a fixed phase. All fifteen
// callers reach the object through GetBattleStruct, and eleven of them also call
// Script::Parameter::ToInt, so this is mostly reached from event-script commands.
extern "C" ARM int IsNotNight(struct S_020103b4* obj) {
    return obj->field3dc != 0;
}
