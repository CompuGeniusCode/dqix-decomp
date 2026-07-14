#include <globaldefs.h>

int DMAMemcpySynchronous(int, unsigned int, unsigned int, unsigned int);
extern "C" int func_020ca408(int, int, int);
extern int data_020f2270;
unsigned int GetSubBg3CharBaseAddr(void);

// USA: func_020c6078
ARM int TransferToSubBg3Char(int arg0, int arg1, unsigned int arg2) {
    unsigned int base = GetSubBg3CharBaseAddr();
    if (data_020f2270 != -1 && arg2 > 0x30) {
        return DMAMemcpySynchronous(data_020f2270, arg0, base + arg1, arg2);
    }
    return func_020ca408(arg0, base + arg1, arg2);
}
