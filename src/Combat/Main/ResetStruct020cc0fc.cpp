#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_020cc0fc
ARM void ResetStruct020cc0fc(char* obj) {
    VectorizedMemset(obj, 0, 0x5c);
    *(int*)(obj + 0x10) = 0;
    *(int*)(obj + 0xc) = 0;
    *(int*)(obj + 0x18) = 0;
    *(int*)(obj + 0x14) = 0;
}
