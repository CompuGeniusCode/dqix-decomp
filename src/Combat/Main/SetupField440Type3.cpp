#include <globaldefs.h>

struct Field440Inner0202f6d4 {
    char unk0[0x8];
    int field8;
    int fieldc;
    int field10;
    int field14;
};

struct Field440Obj0202f6d4 {
    char unk0[0x440];
    struct Field440Inner0202f6d4* field440;
};

// USA: func_0202f6d4
ARM void SetupField440Type3(struct Field440Obj0202f6d4* obj) {
    if (obj->field440 == 0) {
        return;
    }
    obj->field440->field10 = 0x1000;
    obj->field440->field14 = 0x1000;
    obj->field440->field8 = 3;
}
