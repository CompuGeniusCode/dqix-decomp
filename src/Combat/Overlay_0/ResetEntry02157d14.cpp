#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02157d14 {
    char pad0[0x1c];
    short val1c;
    char pad1[0x12];
    int val30;
};

// USA: func_ov000_02157d14
ARM void ResetEntry02157d14(struct Obj02157d14* obj) {
    memset(obj, 0, 0x30);
    obj->val1c = -1;
    obj->val30 = 0;
}
