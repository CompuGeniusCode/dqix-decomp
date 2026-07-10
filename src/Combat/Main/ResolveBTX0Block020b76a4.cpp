#include <globaldefs.h>

// USA: func_020b76a4
ARM void* ResolveBTX0Block020b76a4(void* p) {
    unsigned short off = *(unsigned short*)((char*)p + 0xc);
    unsigned short type = *(unsigned short*)((char*)p + 0xe);
    char* block = (char*)p + off;
    if (type == 1) {
        return (*(unsigned int*)p == 0x30585442)
                 ? (void*)((char*)p + *(unsigned int*)block)
                 : (void*)0;
    }
    return (char*)p + *(unsigned int*)(block + 4);
}
