#include <globaldefs.h>

extern "C" int func_020cf8e4(int);
void* Get2DElementStride0x3c(unsigned char*);

// USA: func_020cf990
ARM long long ComputeEntryByteOffset(int arg0, unsigned char* arg1) {
    int idx = func_020cf8e4(arg0);
    if (idx == -1) {
        return -1;
    }
    int stride = (int)Get2DElementStride0x3c(arg1);
    if (stride == -1) {
        return -1;
    }
    return (long long)idx * 0x15180 + stride;
}
