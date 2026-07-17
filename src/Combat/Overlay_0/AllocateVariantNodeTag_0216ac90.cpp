#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
struct Struct02030b7c { unsigned char pad[0x8]; };
char* GetField4IfField0Zero(struct Struct02030b7c* p);

struct VariantNodeTag0x21 {
    int tag;
    int unused;
    unsigned char value;
    char* str;
};

// USA: func_ov000_0216ac90
ARM int AllocateVariantNodeTag_0216ac90(struct Variant02030b0c* v) {
    struct VariantNodeTag0x21* node = (struct VariantNodeTag0x21*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x21));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x21;
    node->value = (unsigned char)GetIntFromVariant02030b0c(v);
    char* src = GetField4IfField0Zero((struct Struct02030b7c*)((char*)v + 8));
    char* dst = (char*)data_ov000_02184264.alloc->Allocate(strlen(src) + 1);
    node->str = dst;
    strcpy(dst, src);
    func_ov000_02169b78(node);
    return 1;
}
