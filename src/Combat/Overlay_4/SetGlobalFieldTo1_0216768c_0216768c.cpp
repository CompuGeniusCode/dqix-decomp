#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);

// USA: func_ov004_0216768c
ARM int SetGlobalFieldTo1_0216768c_0216768c(void) {
    *(int*)((char*)GetGlobalField0x1c020421a0() + 0x2c8) = 1;
    return 0;
}
