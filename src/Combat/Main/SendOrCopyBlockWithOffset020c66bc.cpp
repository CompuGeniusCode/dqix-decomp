#include <globaldefs.h>

extern "C" int func_020ca408(int, int, int);
int DMAMemcpyAsync(int, unsigned int, unsigned int, unsigned int, void(*)(int), int);
extern int data_020f2270;
extern int data_0211125c;

#pragma optimize_for_size off
// USA: func_020c66bc  (semantic: SendOrCopyBlockWithOffset020c66bc)
extern "C" ARM int func_020c66bc(int param0, int param1, int param2) {
    int val = data_020f2270;
    int extra = *(int*)((char*)&data_0211125c + 0x8);
    if (val != -1) {
        return DMAMemcpyAsync(val, param0, extra + param1, param2, 0, 0);
    } else {
        return func_020ca408(param0, extra + param1, param2);
    }
}
