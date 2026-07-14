#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj020363b4;
void LoadStreamIntoSlot020363b4(struct Obj020363b4* obj, SafeAllocator* alloc, void* header, int size);
void ShiftInBitOnGlobalObject();
void HalveGlobalObjectCounter(void);
int LoadFileIntoMemory(const char*, void*, unsigned int*);
extern int data_0211e33c;

// USA: func_02036294
ARM void LoadResourceStreamByKey02036294(struct Obj020363b4* obj, int key, SafeAllocator* alloc) {
    int local;
    int header;
    ShiftInBitOnGlobalObject();
    header = LoadFileIntoMemory((const char*)key, &data_0211e33c, (unsigned int*)&local);
    if (header != 0) {
        LoadStreamIntoSlot020363b4(obj, alloc, (void*)header, local);
    }
    HalveGlobalObjectCounter();
}
