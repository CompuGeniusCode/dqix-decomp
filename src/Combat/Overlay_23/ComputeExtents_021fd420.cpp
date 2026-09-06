#include <globaldefs.h>

struct Obj021fd420 {
    char pad0[0x22];
    unsigned short f22;
    unsigned short f24;
    unsigned short f26;
    unsigned short f28;
};

// USA: func_ov023_021fd420
ARM void ComputeExtents_021fd420(struct Obj021fd420* obj, unsigned short* out1, unsigned short* out2, unsigned short* out3, unsigned short* out4) {
    *out1 = obj->f22;
    *out2 = obj->f24;
    *out3 = *out1 + obj->f26;
    *out4 = *out2 + obj->f28;
}
