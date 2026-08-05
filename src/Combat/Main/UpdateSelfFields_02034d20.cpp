#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Field0x40Bits_02034d20 {
    unsigned char low3 : 3;
    unsigned char mid5 : 5;
};

struct Obj02034a30_02034d20 {
    unsigned short field0;
    unsigned short field2;
    float field4;
};

struct Self02034e38;

int GetField0x3b4Value(struct BattleStruct* battleStruct);
extern "C" float func_02034a30(struct Obj02034a30_02034d20* obj, int param);
int HwDivideRounded020c2bf4(unsigned int, unsigned int);
void DispatchSelectedMember02034e38(struct Self02034e38* self);

// USA: func_02034d20  (semantic: UpdateSelfFields_02034d20)
extern "C" ARM void func_02034d20(unsigned char* self) {
    struct BattleStruct* bs;
    int fv;
    unsigned short w;

    if (*(int*)(self + 0x6c) & 0x20) {
        return;
    }

    bs = GetBattleStruct();
    fv = GetField0x3b4Value(bs);

    int neq = (0.0f != *(float*)(self + 0x74));
    if (neq) {
        struct Field0x40Bits_02034d20* f40 = (struct Field0x40Bits_02034d20*)(self + 0x40);
        unsigned int bits = f40->mid5;
        float t;
        *(unsigned short*)(self + 0x70) = (unsigned short)((float)bits / 31.0f * 65535.0f);
        t = func_02034a30((struct Obj02034a30_02034d20*)(self + 0x70), fv);
        f40->mid5 = (int)t;
    }

    if (*(int*)(self + 0x6c) & 0x8) {
        unsigned char v = *(unsigned char*)(self + 0x42);
        if (fv < v) {
            *(unsigned char*)(self + 0x42) = v - fv;
        } else {
            *(unsigned char*)(self + 0x42) = 0;
        }
    }

    w = *(unsigned short*)(self + 0x80);
    if (w != 0) {
        if (fv >= w) {
            *(short*)(self + 0x7c) = *(short*)(self + 0x7e);
            *(unsigned short*)(self + 0x80) = 0;
        } else {
            int m;
            *(unsigned short*)(self + 0x80) = w - fv;
            m = HwDivideRounded020c2bf4(*(short*)(self + 0x7e) - *(short*)(self + 0x7c), (unsigned int)(*(unsigned short*)(self + 0x80)) << 12);
            *(short*)(self + 0x7c) = fv * m + *(short*)(self + 0x7c);
        }
    }

    DispatchSelectedMember02034e38((struct Self02034e38*)self);
}
