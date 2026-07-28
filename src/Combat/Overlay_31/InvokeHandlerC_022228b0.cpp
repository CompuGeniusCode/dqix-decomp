#include <globaldefs.h>

#pragma optimize_for_size off

typedef void (*Callback022228b0)(int);

struct Table022228b0 {
    int pad[3];
    Callback022228b0 handler;
};

extern Table022228b0 data_ov031_0224f670;

// USA: func_ov031_022228b0  (semantic: InvokeHandlerC_022228b0)
extern "C" THUMB void func_ov031_022228b0(int arg) {
    data_ov031_0224f670.handler(arg);
}
