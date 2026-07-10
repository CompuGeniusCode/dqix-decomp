#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct02030b7c;
struct Struct02034980;

extern void* GetField4IfField0Zero(struct Struct02030b7c*);
extern void AllocateAndCopyString02034980(struct Struct02034980*, SafeAllocator*, char*);

struct GlobalStringSlot02104b10_45b8 {
    SafeAllocator* alloc;          // 0x0
    struct Struct02034980* dst;    // 0x4
};
extern struct GlobalStringSlot02104b10_45b8 data_02104b10;

// USA: func_020345b8
ARM int AllocGlobalStringFromField020345b8(struct Struct02030b7c* v) {
    char* str = (char*)GetField4IfField0Zero(v);
    AllocateAndCopyString02034980(data_02104b10.dst, data_02104b10.alloc, str);
    return 1;
}
