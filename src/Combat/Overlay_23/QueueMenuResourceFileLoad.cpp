#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021f6bb8(void*);
extern "C" void func_ov023_021f6bb0(void*, int);

extern char strDataStr_021fef64;

// Starts the background load of "data/" plus the file name the descriptor holds at +0x10 and parks
// the task id on the menusys node at ctx+0x118, returning 1 to mean "loading". If the node already
// carries a task id it returns the state the descriptor keeps at +0x1c instead, so the step is safe
// to run every frame; func_ov023_021fb76c is the poll that consumes the file and resets that task id
// to -1, which is what re-arms this step. func_ov023_021fa8fc is the same step for descriptors that
// name a member inside a gp2 archive. What kind of resource the descriptor names is not established.
extern "C" ARM int QueueMenuResourceFileLoad(void* a, void* b) {
    void* sub = func_ov011_021849c8(b);
    if (func_ov023_021f6bb8(sub) >= 0) {
        return *(int*)((char*)a + 0x1c);
    }
    char buf[0x50];
    int builder = (int)BackgroundLoader::GetInstance();
    sprintf(buf, (const char*)&strDataStr_021fef64, *(int*)((char*)a + 0x10));
    int result = ((BackgroundLoader*)(builder))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
    func_ov023_021f6bb0(sub, result);
    return 1;
}
