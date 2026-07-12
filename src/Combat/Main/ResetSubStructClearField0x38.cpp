#include <globaldefs.h>

void ResetStruct02034d04(unsigned char* obj);

// USA: func_020377e8
ARM void ResetSubStructClearField0x38(unsigned char* obj) {
    ResetStruct02034d04(obj + 0x2c);
    *(int*)(obj + 0x38) = 0;
}
