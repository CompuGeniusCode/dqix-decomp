#include <globaldefs.h>
struct D { char pad[8]; unsigned char* ptr; };
extern D dataX;
extern "C" int g4(int, int);
extern "C" int f12(char* p) {
    D* d = &dataX;
    int* aPtr = (int*)(p + 0x5d00);
    unsigned char* ptr = d->ptr;
    int a = *aPtr;
    int b = *(int*)(ptr + 0x18);
    return g4(a, b);
}
