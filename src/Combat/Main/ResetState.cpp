#include <globaldefs.h>

// USA: func_020118fc
ARM void ResetState(void* obj) {
    unsigned char* p = (unsigned char*)obj;
    *(unsigned char*)(p + 0x646c) = 0;
    *(unsigned char*)(p + 0x646d) = 0;
    *(unsigned char*)(p + 0x6470) = 0;
    *(unsigned char*)(p + 0x6471) = 0;
    *(unsigned short*)(p + 0x6472) = 0;
    *(int*)(p + 0x6478) = -1;
    *(unsigned char*)(p + 0x647c) = 0;
    *(unsigned short*)(p + 0x647e) = 0;
}
