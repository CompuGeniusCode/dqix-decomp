#include <globaldefs.h>

extern "C" int func_01ff8adc(unsigned int* stream, int value);
extern unsigned int data_0214e5e4[];

// USA: func_020dc0c8
ARM int EncodeStreamValue020dc0c8(int value) {
    return func_01ff8adc(data_0214e5e4, value);
}
