#include <globaldefs.h>

extern "C" int func_020c9c8c(int, int, int, int);
extern "C" int func_020ca408(int, int, int);
extern unsigned int GetBg0CharBaseAddr(void);
extern int data_020f2270;

// USA: func_020c5dd8
ARM int TransferBg0CharData(int arg0, int arg1, unsigned int arg2) {
    unsigned int base = GetBg0CharBaseAddr();
    if (data_020f2270 != -1 && arg2 > 0x30) {
        return func_020c9c8c(data_020f2270, arg0, base + arg1, arg2);
    }
    return func_020ca408(arg0, base + arg1, arg2);
}
