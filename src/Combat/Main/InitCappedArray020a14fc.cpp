#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Global02109d94 {
    char pad[8];
    SafeAllocator* alloc;
};
extern struct Global02109d94 data_02109d94;

struct Obj020a14fc {
    void* items;              // 0x0
    unsigned short capacity;  // 0x4
    unsigned short used;      // 0x6
    char pad[4];               // 0x8
    void* bitmap;               // 0xc
};

// USA: func_020a14fc
ARM void InitCappedArray020a14fc(struct Obj020a14fc* obj, void* flag, int count) {
    int bitmapSize;
    if (flag == NULL || count == 0) return;

    obj->items = data_02109d94.alloc->Allocate(count * 0xc);
    obj->capacity = (unsigned short)count;
    obj->used = 0;

    bitmapSize = (obj->capacity - 1) / 8 + 1;
    obj->bitmap = data_02109d94.alloc->Allocate(bitmapSize);
}
