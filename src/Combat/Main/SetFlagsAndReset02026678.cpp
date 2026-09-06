#include <globaldefs.h>

void ClearRecords02026644(char* obj);

// USA: func_02026678
ARM void SetFlagsAndReset02026678(char* obj) {
    *(unsigned char*)(obj + 0x9b8) = 1;
    *(unsigned char*)(obj + 0x9b9) = 0;
    ClearRecords02026644(obj);
}
