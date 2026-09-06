#include <globaldefs.h>

extern "C" int f5(char* p) {
    return ((int*)p)[0x1740];
}

extern "C" int f6(char* p) {
    char* q = p + 0x5d00;
    int* r = (int*)q;
    volatile int dummy = 0;
    return *r + dummy;
}

extern "C" int f7(int* p) {
    p = (int*)((char*)p + 0x5d00);
    return *p;
}
