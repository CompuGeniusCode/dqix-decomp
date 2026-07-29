#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* _ZN13SafeAllocator8AllocateEj(void* thisPtr, unsigned int size);

struct Entry020277f4 {
    int value;
    char* str;
    char pad[0x1c];
};

struct Table020277f4 {
    char pad0[0x20];
    Entry020277f4* list;
    int count;
    int capacity;
};

// USA: func_020277f4
ARM void AddNamedEntry020277f4(Table020277f4* obj, int value, const char* key, void* allocator) {
    if (obj->capacity <= obj->count) return;
    obj->list[obj->count].value = value;
    char* buf = (char*)_ZN13SafeAllocator8AllocateEj(allocator, strlen(key) + 1);
    obj->list[obj->count].str = buf;
    strcpy(obj->list[obj->count].str, key);
    obj->count = obj->count + 1;
}
