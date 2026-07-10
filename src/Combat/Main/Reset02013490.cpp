#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_020c1180(void*);

// USA: func_02013490
ARM void Reset02013490(char* obj) {
    *(int*)(obj + 0) = 0;
    *(int*)(obj + 0x38) = 0;
    *(short*)(obj + 4) = 0;
    memset(obj + 6, 0, 9);
    memset(obj + 0xf, 0, 5);
    func_020c1180(obj + 0x14);
    *(int*)(obj + 0x3c) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
}
