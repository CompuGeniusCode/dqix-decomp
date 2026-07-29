#include <globaldefs.h>

#pragma optimize_for_size off
// USA: func_0200d9e4
ARM void* DecodeVlqUnsigned0200d9e4(void* ptr, int* outVal) {
    unsigned int b0 = *(unsigned char*)ptr;
    unsigned int b1, b2, b3, hi, v;
    if (!(b0 & 1)) {
        v = b0 >> 1;
        *outVal = v;
        return (char*)ptr + 1;
    }
    b1 = *((unsigned char*)ptr + 1);
    if (!(b0 & 2)) {
        v = b0 >> 2;
        v = b1 | (v << 8);
        *outVal = v;
        return (char*)ptr + 2;
    }
    b2 = *((unsigned char*)ptr + 2);
    if (!(b0 & 4)) {
        hi = b0 >> 3;
        v = b1 << 8;
        v = v | (hi << 16);
        v = b2 | v;
        *outVal = v;
        return (char*)ptr + 3;
    }
    b3 = *((unsigned char*)ptr + 3);
    hi = b0 >> 3;
    v = b1 << 16;
    v = v | (hi << 24);
    v = v | (b2 << 8);
    v = b3 | v;
    *outVal = v;
    return (char*)ptr + 4;
}
