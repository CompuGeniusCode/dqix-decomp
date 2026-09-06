#include <globaldefs.h>

typedef void (*Callback0200efb8)(void);
extern Callback0200efb8 data_020ef070;

// USA: func_0200efb8  (semantic: InvokeCallback_0200efb8)
extern "C" ARM void func_0200efb8(void) {
    data_020ef070();
}
