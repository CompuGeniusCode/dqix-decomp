#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);

// USA: func_ov004_02165b14
ARM int Function_02165b14(void) {
    int g = GetGlobalField0x1c020421a0();
    *(unsigned char*)(g + 0x1000 + 0x9b2) = 1;
    *(int*)(g + 0x99c) = 2;
    return 0;
}
