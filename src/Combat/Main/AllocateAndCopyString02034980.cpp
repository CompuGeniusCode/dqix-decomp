#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct02034980 {
    char unk[0x1c];
    void* buf;
};

// USA: func_02034980
ARM void AllocateAndCopyString02034980(struct Struct02034980* obj, SafeAllocator* alloc, char* str) {
    void* p = alloc->Allocate(strlen(str) + 1);
    obj->buf = p;
    if (p == NULL) return;
    strcpy((char*)p, str);
}
