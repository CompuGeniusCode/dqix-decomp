#include <globaldefs.h>

int DMAMemcpyAsync(int, unsigned int, unsigned int, unsigned int, void(*)(int), int);
extern "C" int func_020ca408(int, int, int);
extern int data_020f2270;

// USA: func_020c63fc
#pragma optimize_for_size off
ARM int TransferToSubObjExtPalette(int arg0, unsigned int arg1, int arg2) {
    if (data_020f2270 != -1) {
        return DMAMemcpyAsync(data_020f2270, arg0, arg1 + 0x68a0000, arg2, 0, 0);
    }
    return func_020ca408(arg0, arg1 + 0x68a0000, arg2);
}
