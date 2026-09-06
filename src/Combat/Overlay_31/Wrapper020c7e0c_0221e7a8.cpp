#include <globaldefs.h>
#pragma optimize_for_size off

extern "C" int func_020c7e0c(void* a0, int a1, int a2);
extern int data_ov031_0224f4e0;

// USA: func_ov031_0221e7a8  (semantic: Wrapper020c7e0c_0221e7a8)
extern "C" THUMB int func_ov031_0221e7a8(int arg) {
    return func_020c7e0c(&data_ov031_0224f4e0, arg, 0);
}
