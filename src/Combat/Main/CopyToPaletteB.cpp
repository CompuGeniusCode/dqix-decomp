#include <globaldefs.h>

extern "C" void func_020c9cfc(int, int, int, int);
extern "C" int func_020ca3b8(int, int, int);
extern int data_020f2270;

// USA: func_020c5874
ARM void CopyToPaletteB(int src, int dstOffset, unsigned int size) {
    if (data_020f2270 != -1 && size > 0x1c) {
        func_020c9cfc(data_020f2270, src, dstOffset + 0x5000400, size);
    } else {
        func_020ca3b8(src, dstOffset + 0x5000400, size);
    }
}
