#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void* func_02012fe4(void* p);

// USA: func_020a9b2c
ARM int SyncAndCopyBattleData020a9b2c(void* obj) {
    char* argPtr = (char*)obj + 0x198;
    char* r4 = argPtr + 0xc00;
    void* result = func_02012fe4(argPtr);

    void* dst = (char*)result + 0x840;
    char* base1840 = (char*)result + 0x1840;
    *(int*)(base1840 + 0xb38) = *(int*)(r4 + 0xd98);
    *(int*)(base1840 + 0xb34) = *(int*)(r4 + 0xd9c);
    *(int*)(base1840 + 0xb44) = *(int*)(r4 + 0xda0);
    *(int*)(base1840 + 0xb3c) = *(unsigned short*)(r4 + 0xda4) & 0xff;
    unsigned char flag = (*(unsigned char*)(r4 + 0xda6) != 0) ? 1 : 0;
    *(unsigned char*)(base1840 + 0xb61) = flag;
    VectorizedInvertedMemcpy(obj, dst, 0x1b30);
    return 1;
}
