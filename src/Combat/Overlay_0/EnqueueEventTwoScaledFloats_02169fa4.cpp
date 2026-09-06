#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern "C" extern float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44*);

struct EventCtx02169fa4 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx02169fa4 data_ov000_02184264;

struct Event02169fa4 {
    int type;
    int field4;
    unsigned short field8;
    unsigned short fielda;
};

extern "C" void func_ov000_02169b78(struct Event02169fa4*);

// USA: func_ov000_02169fa4  (semantic: EnqueueEventTwoScaledFloats_02169fa4)
extern "C" ARM int func_ov000_02169fa4(struct TaggedValue02030b44* obj) {
    struct Event02169fa4* e = (struct Event02169fa4*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 6;
    e->field8 = (unsigned short)(int)(_ZNK6Script9Parameter7ToFloatEv(obj) * 4096.0f);
    e->fielda = (unsigned short)(int)(_ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)obj + 8)) * 4096.0f);
    func_ov000_02169b78(e);
    return 1;
}
