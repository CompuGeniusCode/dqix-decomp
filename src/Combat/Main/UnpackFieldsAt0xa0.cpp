#include <globaldefs.h>
#pragma optimize_for_size off

extern char data_0210a010;

// USA: func_020b3a5c
ARM void UnpackFieldsAt0xa0(unsigned int* a, unsigned int* b, unsigned int* c, unsigned int* d) {
    if (a) {
        *a = *(unsigned int*)(&data_0210a010 + 0xa0) & 0xff;
    }
    if (b) {
        *b = (*(unsigned int*)(&data_0210a010 + 0xa0) >> 8) & 0xff;
    }
    if (c) {
        *c = (*(unsigned int*)(&data_0210a010 + 0xa0) >> 0x10) & 0xff;
    }
    if (d) {
        *d = (*(unsigned int*)(&data_0210a010 + 0xa0) >> 0x18) & 0xff;
    }
}
