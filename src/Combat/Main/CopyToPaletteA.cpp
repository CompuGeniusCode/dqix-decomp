#include <globaldefs.h>

void DMAMemcpySynchronous16Bit(int, unsigned int, unsigned int, unsigned int);
extern "C" int func_020ca3b8(int, int, int);
extern int data_020f2270;

// USA: func_020c5820
ARM void CopyToPaletteA(int src, int dstOffset, unsigned int size) {
    if (data_020f2270 != -1 && size > 0x1c) {
        DMAMemcpySynchronous16Bit(data_020f2270, src, dstOffset + 0x5000000, size);
    } else {
        func_020ca3b8(src, dstOffset + 0x5000000, size);
    }
}
