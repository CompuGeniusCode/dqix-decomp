#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);

// USA: func_ov004_0216e894
ARM int Function_0216e894(void) {
    int g = GetGlobalField0x1c020421a0();
    g += 0x1000;
    *(unsigned char*)(g + 0x9ca) = 1;
    *(unsigned char*)(g + 0x9af) = 1;
    return 0;
}
