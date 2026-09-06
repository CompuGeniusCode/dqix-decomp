#include <globaldefs.h>

// USA: func_0200f1a0
extern "C" ARM unsigned int func_0200f1a0(void* obj) {
    unsigned char flag = *(unsigned char*)((char*)obj + 0x6a);
    int off60 = *(int*)((char*)obj + 0x60);
    unsigned int adj = flag ? 0x10 : 0;
    unsigned int* p = (unsigned int*)((unsigned int)(*(int*)((char*)obj + 0x18) + off60) - adj);
    int i = 15;
    do {
        unsigned short mask = *(unsigned short*)((char*)obj + 0x68);
        if (mask & (1 << i)) {
            unsigned int v = *--p;
            *(unsigned int*)((char*)obj + i * 4 + 0x1c) = v;
        }
        i--;
    } while (i >= 0);
    *(unsigned int*)((char*)obj + 0x14) = *(int*)((char*)obj + 0x18) + off60;
    return *(unsigned int*)((char*)obj + 0x54);
}
