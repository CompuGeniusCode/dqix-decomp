#include <globaldefs.h>

extern int data_ov017_021d7340;
extern int data_ov017_021d82e0;

// USA: func_ov017_021d6d28
ARM void ComputeChainedSums_021d6d28() {
    float a = *(float*)((char*)&data_ov017_021d7340+0xc) + *(float*)((char*)&data_ov017_021d7340+0x10);
    float b = *(float*)((char*)&data_ov017_021d7340+0x0) + a;
    float c = *(float*)((char*)&data_ov017_021d7340+0x14) + b;
    *(float*)((char*)&data_ov017_021d82e0+0x18) = c;
    float e = *(float*)((char*)&data_ov017_021d82e0+0x14) + *(float*)((char*)&data_ov017_021d7340+0xc);
    float s10 = *(float*)((char*)&data_ov017_021d7340+0x10);
    *(float*)((char*)&data_ov017_021d82e0+0x10) = e;
    float f = e + s10;
    float s0 = *(float*)((char*)&data_ov017_021d7340+0x0);
    *(float*)((char*)&data_ov017_021d82e0+0x8) = f;
    float g = f + s0;
    int s8 = *(int*)((char*)&data_ov017_021d7340+0x8);
    *(float*)((char*)&data_ov017_021d82e0+0xc) = g;
    *(int*)((char*)&data_ov017_021d7340+0x4) = 0xb + s8;
}
