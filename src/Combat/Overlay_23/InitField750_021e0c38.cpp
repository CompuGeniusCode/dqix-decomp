#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct020dfc40;
void ResetAndDetach020dfc6c(struct Struct020dfc40*);


extern int data_020f2a1c;
extern int data_020f2a20;

// USA: func_ov023_021e0c38
ARM int InitField750_021e0c38(void* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();
    ResetAndDetach020dfc6c((struct Struct020dfc40*)((char*)obj + 0xa4));
    *(int*)((char*)obj + 0x750) = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)(data_020f2a1c), (const char*)(data_020f2a20), (SafeAllocator*)(0));
    return 0x3;
}
