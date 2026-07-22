#include <globaldefs.h>

extern "C" void* func_ov031_022133f8(unsigned int flags);

// USA: func_ov031_02214afc
extern "C" ARM char func_ov031_02214afc(int a0) {
    unsigned char i;
    unsigned char count;
    unsigned short flags = *(unsigned short*)((char*)func_ov031_022133f8(0x10) + 0xd16);
    if (flags == 0) return -1;
    i = 0;
    count = 0;
    do {
        if (flags & (1 << i)) {
            if (count == a0) return (char)i;
            count++;
        }
        i++;
    } while (i < 0xd);
    return -1;
}
