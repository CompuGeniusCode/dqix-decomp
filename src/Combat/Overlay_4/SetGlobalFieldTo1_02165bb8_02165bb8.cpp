#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);

// USA: func_ov004_02165bb8
ARM int SetGlobalFieldTo1_02165bb8_02165bb8(void) {
    *(int*)((char*)GetGlobalField0x1c020421a0() + 0x2c8) = 1;
    return 0;
}
