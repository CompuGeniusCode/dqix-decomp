#include <globaldefs.h>

extern "C" void func_ov028_021d8b90(void*);

struct Pair021d9494 { unsigned int v[2]; };
struct S021d9494 {
    char pad[0x84];
    Pair021d9494 dst1; // 0x84
    Pair021d9494 src1; // 0x8c
    unsigned int f94;
    unsigned int f98;
    unsigned char f9c;
    char pad2[3];
    Pair021d9494 dst2; // 0xa0
    Pair021d9494 src2; // 0xa8
};

ARM void ResetBattleFxState_021d9494(S021d9494* obj) {
    func_ov028_021d8b90(obj);
    Pair021d9494 z1 = {0, 0};
    obj->src1 = z1;
    obj->dst1 = obj->src1;
    obj->f98 = 0;
    obj->f94 = 0;
    Pair021d9494 z2 = {0, 0};
    obj->src2 = z2;
    obj->dst2 = obj->src2;
    obj->f9c = 0;
}
