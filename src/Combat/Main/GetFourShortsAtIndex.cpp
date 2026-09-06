#include <globaldefs.h>

struct ShortArrays0204c610 {
    char unk0[0xc];
    short arr0[18]; // 0xc
    short arr1[18]; // 0x30
    short arr2[18]; // 0x54
    short arr3[18]; // 0x78
};

// USA: func_0204c610
ARM void GetFourShortsAtIndex(struct ShortArrays0204c610* base, int index, short* out0, short* out1, short* out2, short* out3) {
    if (index < 0) return;
    if (index >= 18) return;
    *out0 = base->arr0[index];
    *out1 = base->arr1[index];
    *out2 = base->arr2[index];
    *out3 = base->arr3[index];
}
