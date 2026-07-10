#include <globaldefs.h>

extern "C" int func_020c48e4(void);
extern int data_02111240[];

// USA: func_020c63e4
ARM void InitHandleField18(void) {
    data_02111240[6] = func_020c48e4();
}
