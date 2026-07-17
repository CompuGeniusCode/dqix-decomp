#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct BattleStruct* GetBattleStruct();
unsigned int GetBattleScaleCount(struct BattleStruct*);

struct Entry_0205d6a0;
extern "C" void ResetEntryList0205d6a0(struct Entry_0205d6a0*, int);

extern "C" void InitBoxLayout_021d921c(void* obj, int unused, int w, int h);
extern "C" void func_ov023_021d94e4(void* obj, void* buf, int idx);

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);

struct StructA0205d5d0;
extern "C" int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

struct Elem021d90d0 {
    char pad0[0xd8];
    unsigned char fieldD8;
};

struct Obj_021d90d0 {
    char pad0[0x4];
    int field4;
    char pad1[0x118 - 0x8];
    unsigned char field118;
    char pad2[0x11c - 0x119];
    unsigned char field11c;
    signed char field11d;
};

// USA: func_ov023_021d90d0
ARM void UpdatePhase_021d90d0(struct Obj_021d90d0* obj) {
    int scaleCount = GetBattleScaleCount(GetBattleStruct());
    unsigned char state = obj->field11c;
    int flag = scaleCount == 0 ? 1 : scaleCount;

    if (state == 0) {
        ResetEntryList0205d6a0((struct Entry_0205d6a0*)((char*)obj + 0x20), 1);
        obj->field11c = obj->field11c + 1;
        return;
    }
    if (state == 1) {
        obj->field118 = 0;
        obj->field11d = 5;
        memset((void*)obj->field4, 0, 0x960);
        func_ov023_021d94e4(obj, (void*)obj->field4, obj->field118);
        InitBoxLayout_021d921c(obj, obj->field4, 0x1a, 0x14);
        obj->field11c = obj->field11c + 1;
        return;
    }
    if (state != 2) return;

    if (obj->field11d > 0) {
        obj->field11d = obj->field11d - (signed char)flag;
        return;
    }
    obj->field11d = 5;
    obj->field118 = obj->field118 + 1;
    memset((void*)obj->field4, 0, 0x960);
    func_ov023_021d94e4(obj, (void*)obj->field4, obj->field118);

    struct Elem021d90d0* elem = (struct Elem021d90d0*)FindElementByC40205d81c((struct Struct_0205d81c*)((char*)obj + 0x20), 0);
    if (elem != 0) {
        elem->fieldD8 |= 4;
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x20), 0, obj->field4, 1, 0);
        elem->fieldD8 &= ~4;
    }
    if (obj->field118 == 9) {
        obj->field11c = obj->field11c + 1;
    }
}
