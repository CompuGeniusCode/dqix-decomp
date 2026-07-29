#include <globaldefs.h>
#include "std_library_functions.h"

int EncodeStreamFields020dc0e0(int a, int b, int c, int d, unsigned char e, unsigned char f);
extern int data_020e7b68[];

struct Obj0204ade8 {
    unsigned char pad[8];
    int field8;
};
struct CtxD0204ade8 {
    unsigned char pad[0xc];
    int fieldC;
};

// USA: func_0204ade8
ARM void StreamRegisterField0204ade8(struct Obj0204ade8* obj, int streamIdx, int strideElems, struct CtxD0204ade8* d) {
    memcpy(&obj->field8, &d->fieldC, 4);
    EncodeStreamFields020dc0e0(data_020e7b68[streamIdx] + (strideElems << 1), (int)d + 0x10, 0, obj->field8, 1, 0);
}
