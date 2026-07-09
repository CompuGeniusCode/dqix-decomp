#include <globaldefs.h>

struct ByteHeader0204693c {
    signed char byte0;
    signed char byte1;
    signed char byte2;
    signed char byte3;
};

// USA: func_0204693c
ARM void ResetByteHeader(struct ByteHeader0204693c* p) {
    p->byte0 = -1;
    p->byte1 = 0;
    p->byte2 = 0;
    p->byte3 = 0;
}
