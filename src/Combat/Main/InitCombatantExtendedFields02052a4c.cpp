#include <globaldefs.h>
#include "std_library_functions.h"

void SetFlag0x80Reset020489bc(void* obj);
void ClearField0x0_020bc078(int* field);

// USA: func_02052a4c
ARM void InitCombatantExtendedFields02052a4c(void* obj) {
    char* p = (char*)obj;
    SetFlag0x80Reset020489bc(obj);
    *(unsigned short*)p |= 0x100;
    ClearField0x0_020bc078((int*)(p + 0x198));
    *(int*)(p + 0x150) = 0;
    *(int*)(p + 0x154) = 0;
    *(int*)(p + 0x158) = 0;
    memset(p + 0x178, 0, 4);
    *(unsigned char*)(p + 0x17c) = 0;
    *(unsigned char*)(p + 0x17d) = 0;
    *(int*)(p + 0x180) = -1;
    *(unsigned char*)(p + 0x17e) = 0;
    *(unsigned char*)(p + 0x17f) = 0;
    *(unsigned char*)(p + 0x184) = 0;
    *(int*)(p + 0x190) = 0;
    *(int*)(p + 0x194) = -1;
    *(unsigned char*)(p + 0x185) = 0;
    *(unsigned char*)(p + 0x186) = 0;
    *(int*)(p + 0x188) = 0;
    *(int*)(p + 0x1b4) = 0;
    *(int*)(p + 0x1b8) = 0;
    *(int*)(p + 0x1bc) = 0;
    *(int*)(p + 0x18c) = 0;
    *(int*)(p + 0x19c) = 0;
    *(unsigned short*)(p + 0x1b2) = 0;
    *(unsigned short*)(p + 0x1c0) = 0;
    *(int*)(p + 0x15c) = -1;
    *(int*)(p + 0x1c4) = 0;
}
