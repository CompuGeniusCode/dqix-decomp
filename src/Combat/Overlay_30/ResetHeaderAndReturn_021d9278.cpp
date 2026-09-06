#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(struct ByteHeader0204693c* p);

// USA: func_ov030_021d9278
ARM void* ResetHeaderAndReturn_021d9278(void* p) {
    ResetByteHeader((struct ByteHeader0204693c*)p);
    return p;
}
