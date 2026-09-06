#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct VariantNodeTag0x5c {
    int tag;
    int unused;
    unsigned char value;
};

// USA: func_ov000_0216c1ec
ARM int AllocateVariantNodeTag_0216c1ec(struct Variant02030b0c* v) {
    struct VariantNodeTag0x5c* node = (struct VariantNodeTag0x5c*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x5c));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x5c;
    node->value = (unsigned char)_ZNK6Script9Parameter5ToIntEv(v);
    func_ov000_02169b78(node);
    return 1;
}
