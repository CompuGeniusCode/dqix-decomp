#include <globaldefs.h>
extern "C" int g3(int*);
extern "C" int f9(char* p) {
    int* q = (int*)(p + 0x5d00);
    if (g3(q)) return *q;
    return 0;
}
extern "C" int f10(char* p) {
    int* q = (int*)(p + 0x5d00);
    return q[0] + q[1];
}
