#include <globaldefs.h>

extern "C" int func_020c9c8c(int, int, int, int);
extern "C" int func_020ca408(int, int, int);
extern int data_020f2270;
unsigned int GetSubBg2CharBaseAddr(void);

// USA: func_020c5fb8
ARM int TransferToSubBg2Char(int arg0, int arg1, unsigned int arg2) {
    unsigned int base = GetSubBg2CharBaseAddr();
    if (data_020f2270 != -1 && arg2 > 0x30) {
        return func_020c9c8c(data_020f2270, arg0, base + arg1, arg2);
    }
    return func_020ca408(arg0, base + arg1, arg2);
}
