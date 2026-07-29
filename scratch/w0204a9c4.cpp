#include <globaldefs.h>
#include "std_library_functions.h"

int EncodeStreamFields020dc0e0(int a, int b, int c, int d, unsigned char e, unsigned char f);
extern int data_020e7b70[];

struct Obj0204a9c4 {
    int field0;
};
struct CtxD0204a9c4 {
    unsigned char pad[0xc];
    int fieldC;
};

// USA: func_0204a9c4
ARM void StreamRegisterField0204a9c4(struct Obj0204a9c4* obj, int streamIdx, int strideElems, struct CtxD0204a9c4* d) {
    if (d != 0) {
        int localVal;
        memcpy(&localVal, &d->fieldC, 4);
        EncodeStreamFields020dc0e0(data_020e7b70[streamIdx] + (strideElems << 1), (int)((char*)d + 0x10), obj->field0, localVal, 1, 0);
    }
}
