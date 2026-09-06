#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern int data_020f1474;

struct Obj02095e90 {
    char pad[0xa8];
    void* fieldA8;
    char pad2[0x4c4 - 0xa8 - 4];
    int field4c4;
};

// USA: func_02095e90
ARM int InitObjWithAllocator02095e90(struct Obj02095e90* obj, SafeAllocator* allocator) {
    void* ptr = allocator->Allocate(0x198);
    obj->fieldA8 = ptr;
    if (ptr == NULL) {
        return 0;
    }
    memset(ptr, 0, 0x198);
    obj->field4c4 = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFile((const char*)((int)&data_020f1474), (SafeAllocator*)(0));
    return 1;
}
