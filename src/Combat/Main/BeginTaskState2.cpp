#include <globaldefs.h>

struct TaskObj020cb330 {
    char pad0[0x8];
    int field8;    // 0x8
    int flagsC;    // 0xc
    char pad10[0x30 - 0x10];
    int field30;   // 0x30
    short field34; // 0x34
    short field36; // 0x36
    int field38;   // 0x38
};

extern "C" int func_020cb090(struct TaskObj020cb330*, int);

// USA: func_020cb330
ARM int BeginTaskState2(struct TaskObj020cb330* obj, int value) {
    obj->flagsC |= 4;
    obj->field30 = obj->field8;
    obj->field38 = 0;
    obj->field36 = 0;
    obj->field34 = (short)value;
    return func_020cb090(obj, 2);
}
