#include <globaldefs.h>

extern "C" int func_020c9e2c(int, int, int, int, int, int);
extern "C" int func_020ca408(int, int, int);
extern int data_020f2270;

// USA: func_020c6340
#pragma optimize_for_size off
ARM int TransferToSubBgExtPalette(int arg0, unsigned int arg1, int arg2) {
    if (data_020f2270 != -1) {
        return func_020c9e2c(data_020f2270, arg0, arg1 + 0x6898000, arg2, 0, 0);
    }
    return func_020ca408(arg0, arg1 + 0x6898000, arg2);
}
