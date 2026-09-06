#include <globaldefs.h>

extern "C" void _Z20DMAMemcpySynchronousijjj(int channel, unsigned int dst, unsigned int src, unsigned int size);
extern "C" void func_020ca408(void* dst, unsigned int src, unsigned int size);
extern int data_020f2270;

// USA: func_020c5a28
extern "C" ARM void CopyFromVram6400000_020c5a28(void* dst, unsigned int offset, unsigned int size) {
    unsigned int base = 0x6400000;
    if (data_020f2270 != -1 && size > 0x30) {
        _Z20DMAMemcpySynchronousijjj(data_020f2270, (unsigned int)dst, base + offset, size);
    } else {
        func_020ca408(dst, base + offset, size);
    }
}
