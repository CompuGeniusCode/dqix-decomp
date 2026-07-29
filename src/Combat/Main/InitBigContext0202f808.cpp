#include <globaldefs.h>
#include "Filesystem/ExtendedNitroVM.h"

struct Struct0202f700;
void ClearFieldsAndSetLowNibble(struct Struct0202f700*);

extern void* data_02104304;

// USA: func_0202f808  (semantic: InitBigContext0202f808)
extern "C" ARM void func_0202f808(void* obj) {
    ((ExtendedNitroVM*)((char*)obj + 0xc4))->ZeroInitialize();
    *(void**)((char*)&data_02104304 + 4) = obj;
    *(int*)((char*)obj + 0x110) = 0;
    *(int*)((char*)obj + 0x114) = 0;
    *(int*)((char*)obj + 0x118) = 0;
    *(int*)((char*)obj + 0x11c) = 0;
    *(int*)((char*)obj + 0x120) = 0x10000;
    *(int*)((char*)obj + 0x124) = 0;
    *(int*)((char*)obj + 0x788) = 0;
    volatile int* flagsPtr = (volatile int*)((char*)obj + 0x78c);
    int flags = *flagsPtr;
    flags &= ~1;
    flags |= 1;
    *flagsPtr = flags;
    *flagsPtr &= ~8;
    *flagsPtr &= ~0x10;
    char* p = (char*)obj + 0x128;
    int i;
    for (i = 0; i < 0x18; i++, p += 0x44) {
        ClearFieldsAndSetLowNibble((struct Struct0202f700*)p);
    }
}
