#include <globaldefs.h>

int DMAMemcpySynchronous16Bit(int, unsigned int, unsigned int, unsigned int);
extern "C" int func_020ca3b8(int, int, int);
extern unsigned int GetBg3ScreenBaseAddr(void);
extern int data_020f2270;

// USA: func_020c5d18
ARM int TransferBg3ScreenData(int arg0, int arg1, unsigned int arg2) {
    unsigned int base = GetBg3ScreenBaseAddr();
    if (data_020f2270 != -1 && arg2 > 0x1c) {
        return DMAMemcpySynchronous16Bit(data_020f2270, arg0, base + arg1, arg2);
    }
    return func_020ca3b8(arg0, base + arg1, arg2);
}
