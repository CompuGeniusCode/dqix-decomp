#include <globaldefs.h>

extern "C" void func_ov028_021d8b90(void*);

struct Pair021d9494 { unsigned int v[2]; };
struct S021d9494 {
    char pad[0x84];
    Pair021d9494 dst1; // 0x84
    volatile Pair021d9494 src1; // 0x8c
    unsigned int f94;
    unsigned int f98;
    unsigned char f9c;
    char pad2[3];
    Pair021d9494 dst2; // 0xa0
    volatile Pair021d9494 src2; // 0xa8
};

ARM void ResetBattleFxState_021d9494(S021d9494* obj) {
    func_ov028_021d8b90(obj);
    obj->src1.v[0] = 0;
    obj->src1.v[1] = 0;
    obj->dst1.v[0] = obj->src1.v[0];
    obj->dst1.v[1] = obj->src1.v[1];
    obj->f98 = 0;
    obj->f94 = 0;
    obj->src2.v[0] = 0;
    obj->src2.v[1] = 0;
    obj->dst2.v[0] = obj->src2.v[0];
    obj->dst2.v[1] = obj->src2.v[1];
    obj->f9c = 0;
}
