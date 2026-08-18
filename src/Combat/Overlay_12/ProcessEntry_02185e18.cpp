#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"


struct List0202fec8;

struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);

extern "C" void func_020728ac(void* a, void* b, int c, int d, int e, int f, int g);

// USA: func_ov012_02185e18  (semantic: ProcessEntry_02185e18)
extern "C" ARM void func_ov012_02185e18(char* self) {
    int id = (int)BackgroundLoader::GetInstance();
    int field = *(int*)(self + 0x1380);
    int out1, out2;
    ((BackgroundLoader*)((List0202fec8*)id))->GetLoadedFileByID((int)(field), (void**)(&out1), (unsigned int*)(&out2));
    ((SafeAllocator*)(self + 0x34))->Reset();
    func_020728ac(self + 0x133c, self + 0x34, out1, out2, 0, 0, 0);
    *(void**)(self + 0x1378) = FindEntryByKey((struct TableA68*)(self + 0x133c), 0);
    ((BackgroundLoader*)(id))->RemoveTask((int)(*(int*)(self + 0x1380)));
    *(int*)(self + 0x1380) = -1;
}
