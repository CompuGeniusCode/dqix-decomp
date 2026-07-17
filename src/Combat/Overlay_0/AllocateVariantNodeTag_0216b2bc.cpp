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

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern struct TaggedValue02030b44* ConvertTaggedVec3ToFx32(struct TaggedValue02030b44* obj, int* outVec);

struct VariantNodeTag0x31 {
    int tag;
    int unused;
    int vec[3];
    unsigned char flag;
};

// USA: func_ov000_0216b2bc
ARM int AllocateVariantNodeTag_0216b2bc(struct Variant02030b0c* v, int count) {
    struct VariantNodeTag0x31* node = (struct VariantNodeTag0x31*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x31));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x31;
    struct TaggedValue02030b44* tv = ConvertTaggedVec3ToFx32((struct TaggedValue02030b44*)v, node->vec);
    unsigned char flag = 0;
    if (count >= 4) {
        flag = (unsigned char)GetIntFromVariant02030b0c((struct Variant02030b0c*)tv);
    }
    node->flag = flag;
    func_ov000_02169b78(node);
    return 1;
}
