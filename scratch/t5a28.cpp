#include <globaldefs.h>

int DMAMemcpySynchronous(int, unsigned int, unsigned int, unsigned int);
extern "C" int func_020ca408(int, int, int);
extern int data_020f2270;

extern "C" ARM int F(int arg0, int arg1, unsigned int arg2) {
    unsigned int base = 0x6400000;
    if (data_020f2270 == -1) goto fallback;
    if (arg2 <= 0x30) goto fallback;
    return DMAMemcpySynchronous(data_020f2270, arg0, base + arg1, arg2);
fallback:
    return func_020ca408(arg0, base + arg1, arg2);
}
