#include <globaldefs.h>

extern "C" void func_020c7b40(int arg);
extern "C" void func_020c79bc(void);

// USA: func_020d9834
ARM void DispatchByFlag020d9834(int flag) {
    if (flag != 0) {
        func_020c7b40(flag);
    } else {
        func_020c79bc();
    }
}
