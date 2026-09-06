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
struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct VariantNodeTag0x50 {
    int tag;
    int unused;
    short intval;
    short floatval;
};

// USA: func_ov000_0216bd9c
ARM int AllocateVariantNodeTag_0216bd9c(struct Variant02030b0c* v) {
    struct VariantNodeTag0x50* node = (struct VariantNodeTag0x50*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x50));
    node->tag = 0x50;
    node->floatval = (short)(int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)v));
    node->intval = (short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)v + 8));
    func_ov000_02169b78(node);
    return 1;
}
