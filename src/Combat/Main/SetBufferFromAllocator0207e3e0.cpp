#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

struct Obj0207e3e0 {
    char unk[0x5c];
    void* buf;
    unsigned int len;
};

extern "C" void func_0207e264(struct Obj0207e3e0*);

// USA: func_0207e3e0
ARM void SetBufferFromAllocator0207e3e0(struct Obj0207e3e0* obj, AllocatorUnion* alloc, void* src, unsigned int size) {
    void* p = alloc->Allocate(size);
    obj->buf = p;
    if (p == NULL) {
        func_0207e264(obj);
        return;
    }
    memcpy(p, src, size);
    obj->len = size;
}
