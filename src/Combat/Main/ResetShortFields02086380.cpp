#include <globaldefs.h>

void ResetShortFields0x956(unsigned char* obj);

// USA: func_02086380
ARM void ResetShortFields02086380(unsigned char* obj) {
    ResetShortFields0x956(obj);
    *(unsigned short*)(obj + 0x960) = 0;
    *(unsigned short*)(obj + 0x962) = 0;
}
