#include <globaldefs.h>

// USA: func_ov000_02163344
ARM void SetCombatFields02163344(void* obj, int a1, short a2, unsigned char a3, unsigned short a4, unsigned short a5) {
    unsigned char* p = (unsigned char*)obj;
    *(int*)(p + 0x58c4) = a1;
    *(short*)(p + 0x58cc) = a2;
    p[0x58c8] = a3;
    p[0x58c9] = (unsigned char)a4;
    *(unsigned short*)(p + 0x58ca) = a5;
    *(unsigned int*)(p + 0x55f4) |= 0x2000;
}
