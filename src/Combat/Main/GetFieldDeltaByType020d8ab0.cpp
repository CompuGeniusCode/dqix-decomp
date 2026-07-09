#include <globaldefs.h>

// USA: func_020d8ab0
ARM int GetFieldDeltaByType020d8ab0(unsigned char* obj) {
    switch (*(unsigned short*)obj) {
    case 1:
        return *(int*)(obj + 0x2c) - *(int*)(obj + 0x28);
    case 2:
        return 0;
    default:
        return 0;
    }
}
