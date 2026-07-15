#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct VariantNodeTag0x44 {
    int tag;
    int unused;
    int value;
};

// USA: func_ov000_0216ba14
ARM int AllocateVariantNodeTag_0216ba14_0216ba14(struct Variant02030b0c* v) {
    struct VariantNodeTag0x44* node = (struct VariantNodeTag0x44*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x44));
    if (node == NULL) return 0;
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x44;
    node->value = GetIntFromVariant02030b0c(v);
    func_ov000_02169b78(node);
    return 1;
}
