#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

void ClearStruct16(void* p);

extern int data_020f2a1c;
extern int data_020f2b68;

// USA: func_ov023_021e07f8
ARM int InitField744_021e07f8(void* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();
    ClearStruct16((char*)obj + 0x6c);
    *(int*)((char*)obj + 0x744) = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)(data_020f2a1c), (const char*)(data_020f2b68), (SafeAllocator*)(0));
    return 0xa;
}
