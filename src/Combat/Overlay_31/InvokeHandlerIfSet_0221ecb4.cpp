#include <globaldefs.h>

#pragma optimize_for_size off

typedef void (*Callback0221ecb4)(int);

struct Table0221ecb4 {
    int pad;
    Callback0221ecb4 handler;
};

extern Table0221ecb4 data_ov031_0224f4c0;

// USA: func_ov031_0221ecb4  (semantic: InvokeHandlerIfSet_0221ecb4)
extern "C" THUMB int func_ov031_0221ecb4(int arg) {
    Callback0221ecb4 handler = data_ov031_0224f4c0.handler;
    if (handler != NULL) {
        handler(arg);
    }
    return 0;
}
