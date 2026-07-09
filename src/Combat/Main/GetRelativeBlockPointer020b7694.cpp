#include <globaldefs.h>

// USA: func_020b7694
ARM void* GetRelativeBlockPointer020b7694(unsigned char* base) {
    int rel = *(int*)(base + *(unsigned short*)(base + 0xc));
    return base + rel;
}
