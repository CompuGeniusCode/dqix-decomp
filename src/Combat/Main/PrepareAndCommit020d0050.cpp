#include <globaldefs.h>

int ForwardIsFlag4Clear020d0840(void);
int ForwardWaitForField0x114Bit4ClearIsNull020d0834(void);
void UnlockCardReadManager(unsigned short, int);
typedef void (*UnlockCardReadManagerRawFn)(int, int);

// USA: func_020d0050
ARM void PrepareAndCommit020d0050(int a) {
    if (!ForwardIsFlag4Clear020d0840()) {
        ForwardWaitForField0x114Bit4ClearIsNull020d0834();
    }
    ((UnlockCardReadManagerRawFn)&UnlockCardReadManager)(a, 2);
}
