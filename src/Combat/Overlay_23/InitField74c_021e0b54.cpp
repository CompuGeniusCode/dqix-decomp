#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

void ClearStruct16(void* p);

extern int data_020f2a1c;
extern int data_020f2a28;

// USA: func_ov023_021e0b54
ARM int InitField74c_021e0b54(void* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();
    ClearStruct16((char*)obj + 0x7c);
    *(int*)((char*)obj + 0x74c) = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)(data_020f2a1c), (const char*)(data_020f2a28), (SafeAllocator*)(0));
    return 0xe;
}
