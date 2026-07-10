#include <globaldefs.h>

extern char data_020fe9cc;
void CleanInvalidateDataCacheRange(int addr, int size);
extern "C" void func_020c5b98(void* p, int a, int b);

// USA: func_0202adf0
ARM void FlushAndClearBuffer0202adf0() {
    CleanInvalidateDataCacheRange((int)&data_020fe9cc, 0x600);
    func_020c5b98(&data_020fe9cc, 0, 0x600);
}
