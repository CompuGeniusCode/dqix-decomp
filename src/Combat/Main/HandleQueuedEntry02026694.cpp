#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


extern "C" int func_02026780(void* self, int a, int b);

struct List0202fec8;

extern int data_020ef6d7;

// USA: func_02026694
ARM void HandleQueuedEntry02026694(char* self) {
    int obj;
    int out1;
    int out2;

    if (*(unsigned char*)(self + 0x9b8) == 0) {
        return;
    }

    obj = (int)BackgroundLoader::GetInstance();

    if (*(unsigned char*)(self + 0x9b9) == 0) {
        ((BackgroundLoader*)(obj))->RemoveTask((int)(*(int*)(self + 0xa2c)));
        ((BackgroundLoader*)((unsigned char*)obj))->AddFence();
        *(int*)(self + 0xa2c) = ((BackgroundLoader*)(obj))->QueueLoadFile((const char*)((int)&data_020ef6d7), (SafeAllocator*)(0));
        *(unsigned char*)(self + 0x9b9) += 1;
        return;
    }

    if (*(unsigned char*)(self + 0x9b9) != 1) {
        return;
    }

    if (((BackgroundLoader*)(obj))->GetTaskStatus((int)(*(int*)(self + 0xa2c))) == 0) {
        return;
    }

    out1 = 0;
    out2 = 0;
    ((BackgroundLoader*)((struct List0202fec8*)obj))->GetLoadedFileByID((int)(*(int*)(self + 0xa2c)), (void**)(&out1), (unsigned int*)(&out2));

    if (func_02026780(self, out1, out2) == 0) {
        *(unsigned char*)(self + 0x9ba) = 1;
    } else {
        *(unsigned char*)(self + 0x779) = 1;
        *(unsigned char*)(self + 0x9ba) = 1;
    }

    ((BackgroundLoader*)(obj))->RemoveTask((int)(*(int*)(self + 0xa2c)));
    *(int*)(self + 0xa2c) = -1;
    *(unsigned char*)(self + 0x9b8) = 0;
    *(unsigned char*)(self + 0x9b9) += 1;
}
