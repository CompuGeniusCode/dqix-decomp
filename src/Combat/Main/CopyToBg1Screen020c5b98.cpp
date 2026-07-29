#include <globaldefs.h>

void DMAMemcpySynchronous16Bit(int, unsigned int, unsigned int, unsigned int);
extern "C" int func_020ca3b8(int, int, int);
extern int data_020f2270;
unsigned int GetBg1ScreenBaseAddr(void);

// USA: func_020c5b98  (semantic: CopyToBg1Screen020c5b98)
extern "C" ARM void func_020c5b98(int src, int offset, unsigned int size) {
    unsigned int base = GetBg1ScreenBaseAddr();
    if (data_020f2270 != -1 && size > 0x1c) {
        DMAMemcpySynchronous16Bit(data_020f2270, src, base + offset, size);
    } else {
        func_020ca3b8(src, base + offset, size);
    }
}
