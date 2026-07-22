#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_02169b78(void* node);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct TagNode02169bb4 {
    int tag;
    int unused;
};

// USA: func_ov000_02169bb4  (semantic: AllocateAndEnqueueTagNode_02169bb4)
extern "C" ARM void func_ov000_02169bb4(int tag) {
    struct TagNode02169bb4* node = (struct TagNode02169bb4*)data_ov000_02184264.alloc->Allocate(8);
    if (node == NULL) return;
    node->tag = 0;
    node->unused = 0;
    node->tag = tag;
    func_ov000_02169b78(node);
}
