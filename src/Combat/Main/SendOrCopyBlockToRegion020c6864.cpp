#include <globaldefs.h>

extern "C" int func_020ca408(int, int, int);
int DMAMemcpyAsync(int, unsigned int, unsigned int, unsigned int, void(*)(int), int);
extern int data_020f2270;
extern int data_0211125c;

#pragma optimize_for_size off
// USA: func_020c6864
ARM int SendOrCopyBlockToRegion020c6864(int param0, int param1) {
    int extra = *(int*)((char*)&data_0211125c + 0x10) + 0x20000;
    int val = data_020f2270;
    if (val != -1) {
        return DMAMemcpyAsync(val, param0, extra, param1, 0, 0);
    }
    return func_020ca408(param0, extra, param1);
}
