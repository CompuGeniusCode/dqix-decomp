#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct020dfc40;
void ResetAndDetach020dfc6c(struct Struct020dfc40*);


extern int data_020f2a1c;
extern int data_020f2a10;

// USA: func_ov023_021e0a48
ARM int InitField748_021e0a48(void* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();
    ResetAndDetach020dfc6c((struct Struct020dfc40*)((char*)obj + 0x8c));
    *(int*)((char*)obj + 0x748) = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)(data_020f2a1c), (const char*)(data_020f2a10), (SafeAllocator*)(0));
    return 0xc;
}
