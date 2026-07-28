#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);

// USA: func_ov004_02165af4
ARM int Function_02165af4(void) {
    int g = GetGlobalField0x1c020421a0();
    *(unsigned char*)(g + 0x1000 + 0x9b2) = 1;
    *(int*)(g + 0x99c) = 1;
    return 0;
}
