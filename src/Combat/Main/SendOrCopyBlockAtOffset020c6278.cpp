#include <globaldefs.h>

extern "C" int func_020ca408(int, int, int);
int DMAMemcpyAsync(int, unsigned int, unsigned int, unsigned int, void(*)(int), int);
extern int data_020f2270;
extern int data_02111240[];

#pragma optimize_for_size off
// USA: func_020c6278
ARM int SendOrCopyBlockAtOffset020c6278(int arg0, int arg1, int arg2) {
    int addr = data_02111240[1] + arg1;
    int val = data_020f2270;
    if (val != -1) {
        return DMAMemcpyAsync(val, arg0, addr, arg2, 0, 0);
    }
    return func_020ca408(arg0, addr, arg2);
}
