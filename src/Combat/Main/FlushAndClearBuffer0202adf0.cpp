#include <globaldefs.h>

extern char data_020fe9cc;
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" void func_020c5b98(void* p, int a, int b);

// USA: func_0202adf0
ARM void FlushAndClearBuffer0202adf0() {
    CleanInvalidateCacheRange((const void*)((int)&data_020fe9cc), 0x600);
    func_020c5b98(&data_020fe9cc, 0, 0x600);
}
