#include <globaldefs.h>

struct State0xc0cc {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    short unk14;
};

// USA: func_0203c0cc
ARM void InitFields0x0(struct State0xc0cc* obj) {
    obj->unk4 = 0;
    obj->unk0 = 0;
    obj->unk8 = 0;
    obj->unk10 = 0;
    obj->unkC = 0;
    obj->unk14 = -1;
}
