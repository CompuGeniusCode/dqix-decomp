#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_02026644
ARM void ClearRecords02026644(char* obj) {
    if (((unsigned char*)obj)[0x12] != 0) {
        obj[0x779] = 0;
        obj[0x9ba] = 0;
    }
    obj[0x780] = 0;
    VectorizedMemset(obj + 0x784, 0, 0x230);
}
