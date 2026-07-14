#include <globaldefs.h>

int DMAMemcpySynchronous16Bit(int, unsigned int, unsigned int, unsigned int);
extern "C" int func_020ca3b8(int, int, int);
extern int data_020f2270;

// USA: func_020c58cc
ARM int TransferMainObjPalette(int arg0, int arg1, unsigned int arg2) {
    if (data_020f2270 != -1 && arg2 > 0x1c) {
        return DMAMemcpySynchronous16Bit(data_020f2270, arg0, arg1 + 0x5000200, arg2);
    }
    return func_020ca3b8(arg0, arg1 + 0x5000200, arg2);
}
