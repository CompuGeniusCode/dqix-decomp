#include <globaldefs.h>

#pragma optimize_for_size off
// USA: func_0200d9e4
ARM void* DecodeVlqUnsigned0200d9e4(void* ptr, int* outVal) {
    unsigned int b0 = *(unsigned char*)ptr;
    if (!(b0 & 1)) {
        unsigned int v = b0 >> 1;
        *outVal = v;
        return (char*)ptr + 1;
    } else {
        unsigned int b1 = *((unsigned char*)ptr + 1);
        if (!(b0 & 2)) {
            unsigned int v = b1 | ((b0 >> 2) << 8);
            *outVal = v;
            return (char*)ptr + 2;
        } else {
            unsigned int b2 = *((unsigned char*)ptr + 2);
            if (!(b0 & 4)) {
                unsigned int v = b2 | (b1 << 8) | ((b0 >> 3) << 16);
                *outVal = v;
                return (char*)ptr + 3;
            } else {
                unsigned int b3 = *((unsigned char*)ptr + 3);
                unsigned int v = b3 | (b1 << 16) | ((b0 >> 3) << 24) | (b2 << 8);
                *outVal = v;
                return (char*)ptr + 4;
            }
        }
    }
}
