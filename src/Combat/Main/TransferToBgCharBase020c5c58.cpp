#include <globaldefs.h>

extern "C" int func_020c9cfc(int, int, int, int);
extern "C" int func_020ca3b8(int, int, int);
extern int data_020f2270;

ARM unsigned int GetBgCharBaseAddress020c4d1c(void);

// USA: func_020c5c58
ARM int TransferToBgCharBase020c5c58(int arg0, int arg1, unsigned int arg2) {
    unsigned int base = GetBgCharBaseAddress020c4d1c();
    if (data_020f2270 != -1 && arg2 > 0x1c) {
        return func_020c9cfc(data_020f2270, arg0, base + arg1, arg2);
    }
    return func_020ca3b8(arg0, base + arg1, arg2);
}
