#include <globaldefs.h>

extern "C" int func_01ff891c(unsigned int* stream, int value);
extern unsigned int data_0214e5e4[];

// USA: func_020dc0b0
ARM int EncodeStreamValue020dc0b0(int value) {
    return func_01ff891c(data_0214e5e4, value);
}
