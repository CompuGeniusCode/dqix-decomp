#include <globaldefs.h>

extern "C" int func_01ff8b48(unsigned int* stream, int a, int b, int c, int d, int e, int f);
extern unsigned int data_0214e5e4[];

// USA: func_020dc0e0
ARM int EncodeStreamFields020dc0e0(int a, int b, int c, int d, unsigned char e, unsigned char f) {
    return func_01ff8b48(data_0214e5e4, a, b, c, d, e, f);
}
