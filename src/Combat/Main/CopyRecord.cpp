#include <globaldefs.h>

struct CopyPayload {
    char data[0x30];
};

struct CopyableRecord {
    struct CopyPayload payload;
    short f30;
    signed char f32;
    unsigned char f33;
};

// USA: func_02093b54
ARM void CopyRecord(struct CopyableRecord* dst, struct CopyableRecord* src) {
    dst->payload = src->payload;
    dst->f30 = src->f30;
    dst->f32 = src->f32;
    dst->f33 = src->f33;
}
