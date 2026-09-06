#include <globaldefs.h>

struct StateHolder022112e4 {
    int* state;
};

extern StateHolder022112e4 data_ov031_0224e590;

// USA: func_ov031_022112e4
ARM void* GetFieldIfOtherFieldZero_022112e4(void) {
    int* state = data_ov031_0224e590.state;
    if (state != NULL) {
        if (*(int*)((char*)state + 0x30) == 0) {
            return *(void**)((char*)state + 0x2c);
        }
    }
    return NULL;
}
