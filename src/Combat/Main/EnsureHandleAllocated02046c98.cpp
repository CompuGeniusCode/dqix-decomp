#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern int data_020f00cc;

struct Handle02046c98 {
    unsigned char pad[0xe8];
    int f_e8;   // 0xe8
    int f_ec;   // 0xec
};

// USA: func_02046c98
ARM void EnsureHandleAllocated02046c98(struct Handle02046c98* h) {
    if (h->f_e8 != 0) return;
    h->f_ec = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFile((const char*)((int)&data_020f00cc), (SafeAllocator*)(0));
}
