#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };
struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);
extern struct TaggedValue02030b44* ConvertTaggedVec3ToFx32(struct TaggedValue02030b44* obj, int* outVec);

struct VariantNodeTag0x58 {
    int tag;
    int unused;
    int vec1[3];
    int vec2[3];
};

// USA: func_ov000_0216bfa4  (semantic: AllocateVariantNodeTag_0216bfa4)
extern "C" ARM int func_ov000_0216bfa4(struct Variant02030b0c* v) {
    struct VariantNodeTag0x58* node = (struct VariantNodeTag0x58*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x58));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x58;
    struct TaggedValue02030b44* tv = ConvertTaggedVec3ToFx32((struct TaggedValue02030b44*)v, node->vec1);
    node->vec2[0] = (int)(4096.0f * GetTaggedValueAsFloat(tv + 0));
    node->vec2[1] = (int)(4096.0f * GetTaggedValueAsFloat(tv + 1));
    node->vec2[2] = (int)(4096.0f * GetTaggedValueAsFloat(tv + 2));
    func_ov000_02169b78(node);
    return 1;
}
