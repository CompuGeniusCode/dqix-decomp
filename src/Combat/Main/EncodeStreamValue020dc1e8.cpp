#include <globaldefs.h>

extern "C" int func_01ff8f00(unsigned int* stream, int value);
extern unsigned int data_0214e5e4[];

// USA: func_020dc1e8
ARM int EncodeStreamValue020dc1e8(int value) {
    return func_01ff8f00(data_0214e5e4, value);
}
