#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern int data_ov014_021896bc;

// USA: func_ov014_02185c48  (semantic: Trans_02185c48)
extern "C" ARM unsigned int func_ov014_02185c48(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r4 = r0;
    r0 = *(unsigned char*)((char*)r4 + 0x81);
    cc = (int)(r0 & 0x10);
    if (cc == 0) { return r0; }
    r0 = (unsigned int)(int)BackgroundLoader::GetInstance();
    r1 = *(unsigned char*)((char*)r4 + 0x7e);
    cc = (int)(r1) - (int)(0x0);
    if (cc != 0) { return r0; }
    r1 = (unsigned int)&data_ov014_021896bc;
    r2 = 0x0;
    r0 = (unsigned int)((BackgroundLoader*)(r0))->QueueLoadFile((const char*)(r1), (SafeAllocator*)(r2));
    *(unsigned int*)((char*)r4 + 0x70) = (unsigned int)r0;
    r0 = *(unsigned char*)((char*)r4 + 0x7e);
    r0 = r0 + 0x1;
    *(unsigned char*)((char*)r4 + 0x7e) = (unsigned char)r0;
    return r0;
}
