#include <globaldefs.h>

extern "C" int func_020c9cfc(int, int, int, int);
extern "C" int func_020ca3b8(int, int, int);
extern "C" unsigned int func_020c4da0(void);
extern int data_020f2270;

// USA: func_020c5cb8
ARM int TransferSubBg2ScreenData(int arg0, int arg1, unsigned int arg2) {
    unsigned int base = func_020c4da0();
    if (data_020f2270 != -1 && arg2 > 0x1c) {
        return func_020c9cfc(data_020f2270, arg0, base + arg1, arg2);
    }
    return func_020ca3b8(arg0, base + arg1, arg2);
}
