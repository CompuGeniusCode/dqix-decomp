#include <globaldefs.h>

int AwaitCardReadManagerIdle(void);

// USA: func_020d0834
ARM int ForwardWaitForField0x114Bit4ClearIsNull020d0834(void) {
    return AwaitCardReadManagerIdle();
}
