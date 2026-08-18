#include <globaldefs.h>
#pragma opt_propagation off
int DMAMemcpySynchronous(int, unsigned int, unsigned int, unsigned int);
extern "C" int func_020ca408(int, int, int);
extern int data_020f2270;

// USA: func_020c5a28
ARM int TransferMainObjCharData_020c5a28(int arg0, int arg1, unsigned int arg2) {
    int vram = 0x6400000;
    if (data_020f2270 != -1 && arg2 > 0x30) {
        return DMAMemcpySynchronous(data_020f2270, arg0, (unsigned int)(vram + arg1), arg2);
    }
    return func_020ca408(arg0, vram + arg1, arg2);
}
