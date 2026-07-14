#include <globaldefs.h>

int DMAMemcpySynchronous(int, unsigned int, unsigned int, unsigned int);
extern "C" int func_020ca408(int, int, int);
extern unsigned int GetBg1CharBaseAddr(void);
extern int data_020f2270;

// USA: func_020c5e98
ARM int TransferBg1CharData(int arg0, int arg1, unsigned int arg2) {
    unsigned int base = GetBg1CharBaseAddr();
    if (data_020f2270 != -1 && arg2 > 0x30) {
        return DMAMemcpySynchronous(data_020f2270, arg0, base + arg1, arg2);
    }
    return func_020ca408(arg0, base + arg1, arg2);
}
