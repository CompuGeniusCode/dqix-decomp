#include <globaldefs.h>

#pragma optimize_for_size off

typedef void (*Callback0221e470)(int);
extern Callback0221e470 data_ov031_0224f4cc;

// USA: func_ov031_0221e470  (semantic: InvokeWithSecondArg_0221e470)
extern "C" THUMB void func_ov031_0221e470(int unused, int arg) {
    data_ov031_0224f4cc(arg);
}
