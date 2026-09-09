#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

void* LoadFileIntoMemory(const char*, void*, unsigned int*);

extern "C" void func_0203fd5c(void* p0, void* buf, int p2, void* p3);

extern char strDataAniStr[];
extern char fileStagingBuffer[];

// Reads one sprite out of data/ani and hands the buffer to the cache-entry builder
// func_0203fd5c. The test on the last character being 'r' is really an extension test:
// .spr is the only lowercase extension in data/ani, so .pac, .gp2 and .lia names reach
// here and silently load nothing. The single caller, func_0204027c, owns a refcounted
// table keyed by file name, and the BackgroundLoader lock is held across the blocking
// read because the destination is the one shared staging buffer.
extern "C" ARM void LoadSprFileIntoCacheEntry(void* p0, char* p1, int p2) {
    char buf[0x80];
    char* end = p1 + strlen(p1);
    if (end[-1] == 'r') {
        sprintf(buf, strDataAniStr, p1);
        BackgroundLoader::AddLockGlobal();
        void* result = LoadFileIntoMemory(buf, fileStagingBuffer, (unsigned int*)0);
        if (result != NULL) {
            func_0203fd5c(p0, buf, p2, result);
        }
        BackgroundLoader::RemoveLockGlobal();
    }
}
