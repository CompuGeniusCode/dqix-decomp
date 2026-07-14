#include <globaldefs.h>

int DMAMemcpySynchronous16Bit(int, unsigned int, unsigned int, unsigned int);
extern "C" int func_020ca3b8(int, int, int);
extern int data_020f2270;

ARM unsigned int GetSubBg0ScreenBaseAddr(void);

// USA: func_020c5b38
ARM int TransferToSubBg0ScreenBase(int arg0, int arg1, unsigned int arg2) {
    unsigned int base = GetSubBg0ScreenBaseAddr();
    if (data_020f2270 != -1 && arg2 > 0x1c) {
        return DMAMemcpySynchronous16Bit(data_020f2270, arg0, base + arg1, arg2);
    }
    return func_020ca3b8(arg0, base + arg1, arg2);
}
