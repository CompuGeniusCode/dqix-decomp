#include <globaldefs.h>

int IsCardReadManagerIdle(void);

// USA: func_020d0840
ARM int ForwardIsFlag4Clear020d0840(void) {
    return IsCardReadManagerIdle();
}
