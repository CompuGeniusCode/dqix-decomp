#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

char* AllocateStringCopy020da150(SafeAllocator* allocator, const char* src);

struct EntryDf618 {
    void* name;
    void* desc;
    unsigned char data[0x18];
};
struct BitFieldDf618 {
    unsigned short counter : 15;
    unsigned short flag : 1;
};

// USA: func_020df618
ARM int CopyEntryAndAllocateStrings020df618(SafeAllocator* allocator, void* b, EntryDf618* dst, void** e, int unused, EntryDf618* src) {
    memcpy(dst, src, sizeof(EntryDf618));
    dst->desc = (src->desc != NULL) ? AllocateStringCopy020da150(allocator, (const char*)src->desc) : NULL;
    dst->name = NULL;
    if (src->name != NULL && *e != NULL) {
        dst->name = *e;
        *e = (char*)dst->name + 0x20;
        memcpy(dst->name, src->name, 0x20);
        ((BitFieldDf618*)((char*)b + 2))->counter++;
    }
    return 1;
}
