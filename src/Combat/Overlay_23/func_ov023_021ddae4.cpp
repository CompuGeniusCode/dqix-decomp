#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"


struct List0202fec8;

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

extern "C" void func_0205a528(void* a, void* ptr, int val, void* d);

// USA: func_ov023_021ddae4  (semantic: ProcessListAndResetAllocator_021ddae4)
extern "C" ARM void func_ov023_021ddae4(void* obj) {
    if (*(int*)((char*)obj + 0x780) < 0) {
        return;
    }
    int listPtr = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(*(int*)((char*)obj + 0x780)))) {
        return;
    }
    ((SafeAllocator*)(*(void**)((char*)obj + 0x44)))->Reset();
    void* dummyOut;
    int out1, out2;
    int fieldOut;
    ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(*(int*)((char*)obj + 0x780)), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 != 0 && out2 != 0) {
        int count = CountActiveEntries((struct ActiveEntry02046900*)out1);
        for (int i = 0; i < count; i++) {
            void* result = FindRecordByIndex((struct Rec020467f0*)out1, i, &dummyOut, &fieldOut);
            func_0205a528((char*)obj + 0x12c, result, fieldOut, *(void**)((char*)obj + 0x44));
        }
    }
    *(signed char*)((char*)obj + 0x77d) = *(signed char*)((char*)obj + 0x77e);
    ((BackgroundLoader*)(listPtr))->RemoveTask((int)(*(int*)((char*)obj + 0x780)));
    *(int*)((char*)obj + 0x780) = -1;
}
