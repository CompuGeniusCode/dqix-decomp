#include <globaldefs.h>

extern "C" int func_020c9c8c(int, int, int, int);
extern "C" int func_020ca408(int, int, int);
extern int data_020f2270;

// USA: func_020c59d0
ARM int TransferSubOam(int arg0, int arg1, unsigned int arg2) {
    if (data_020f2270 != -1 && arg2 > 0x30) {
        return func_020c9c8c(data_020f2270, arg0, arg1 + 0x7000400, arg2);
    }
    return func_020ca408(arg0, arg1 + 0x7000400, arg2);
}
