#include <globaldefs.h>

// USA: func_020113a8
ARM void SetBitInArray(void* obj, int a, int b) {
    unsigned int n = (a - 1) * 5 + b;
    unsigned int byte = n >> 3;
    unsigned char* p = (unsigned char*)obj + 0x5cd0;
    p[byte] |= (unsigned char)(1 << (n - (byte << 3)));
}
