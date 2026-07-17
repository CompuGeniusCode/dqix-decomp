#include <globaldefs.h>

int IsStateSeven_02210ef8(void);
int ReceiveLoop_0221042c(void* a);

// USA: func_ov031_0221032c
ARM int CheckAndProcess_0221032c(void* a) {
    int result = -0x38;
    if (IsStateSeven_02210ef8()) {
        result = ReceiveLoop_0221042c(a);
    }
    return result;
}
