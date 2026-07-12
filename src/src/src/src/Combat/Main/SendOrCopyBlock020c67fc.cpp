#include <globaldefs.h>

extern "C" int func_020ca408(int, int, int);
extern "C" int func_020c9e2c(int, int, int, int, int, int);
extern int data_020f2270;
extern int data_0211125c;

#pragma optimize_for_size off
// USA: func_020c67fc
ARM int SendOrCopyBlock020c67fc(int param0, int param1) {
    int val = data_020f2270;
    int extra = *(int*)((char*)&data_0211125c + 0x10);
    if (val != -1) {
        return func_020c9e2c(val, param0, extra, param1, 0, 0);
    }
    return func_020ca408(param0, extra, param1);
}
