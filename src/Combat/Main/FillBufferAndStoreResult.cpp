#include <globaldefs.h>

extern "C" void CpuSet(const void*, void*, unsigned int);
extern "C" int func_020c7080(void);

extern int data_0211214c;
extern char data_02112148;

// USA: func_020d12e4
ARM void FillBufferAndStoreResult(void) {
    int zero = 0;
    CpuSet(&zero, &data_0211214c, 0x5000001);
    int result = func_020c7080();
    *(short*)(&data_02112148 + 0x6) = (short)result;
}
