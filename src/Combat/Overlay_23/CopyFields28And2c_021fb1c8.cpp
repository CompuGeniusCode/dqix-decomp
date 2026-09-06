#include <globaldefs.h>

struct SrcFields021fb1c8 {
    int field0;
    int field4;
};

struct DstFields021fb1c8 {
    char pad[0x28];
    int field28;
    int field2c;
};

// USA: func_ov023_021fb1c8
ARM void CopyFields28And2c_021fb1c8(struct DstFields021fb1c8* dst, struct SrcFields021fb1c8* src) {
    dst->field28 = src->field0;
    dst->field2c = src->field4;
}
