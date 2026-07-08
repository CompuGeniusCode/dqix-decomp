#include <globaldefs.h>

struct PairStruct {
    int unk0;
    int unk4;
    int f8;
    int fc;
};

// USA: func_02036e20
ARM void CopyFields0x8And0xC(struct PairStruct* src, struct PairStruct* dst) {
    dst->f8 = src->f8;
    dst->fc = src->fc;
}
