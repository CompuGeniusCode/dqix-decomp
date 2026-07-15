#include <globaldefs.h>

extern "C" int func_ov031_0223cf70(void*);
extern void* data_ov031_02290cfc;

// USA: func_ov031_02235c5c
ARM int TailCallPtrToGlobal_02235c5c(void) {
    return func_ov031_0223cf70(&data_ov031_02290cfc);
}
