#include <globaldefs.h>
struct D { char pad[8]; int* ptr; };
extern D dataX;
extern "C" int g4(int, int);
extern "C" int f11(char* p) {
    int a = *(int*)(p + 0x5d00);
    int b = *(int*)((char*)dataX.ptr + 0x18);
    return g4(a, b);
}
