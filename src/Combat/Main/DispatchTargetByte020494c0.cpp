#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_02033920(void* obj, int value, int arg3);

struct Sub020494c0 {
    char pad[0x4c];
    unsigned char field_4c;
    unsigned char field_4d;
};

struct Obj020494c0 {
    char pad[0x13c];
    struct Sub020494c0* field_13c;
};

// USA: func_020494c0
ARM void DispatchTargetByte020494c0(struct Obj020494c0* obj) {
    struct Sub020494c0* p;
    unsigned char v;
    if (obj->field_13c == NULL) return;
    GetBattleStruct();
    p = obj->field_13c;
    v = p->field_4c;
    if (v == 0xff) v = p->field_4d;
    func_02033920(obj, v, 0);
}
