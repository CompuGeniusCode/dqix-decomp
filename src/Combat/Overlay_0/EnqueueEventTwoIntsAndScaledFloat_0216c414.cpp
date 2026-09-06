#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern "C" extern float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44*);

struct Variant02030b0c;
extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);

struct EventCtx0216c414 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216c414 data_ov000_02184264;

struct Event0216c414 {
    int type;
    int field4;
    unsigned short field8;
    unsigned short fielda;
    unsigned short fieldc;
};

extern "C" void func_ov000_02169b78(struct Event0216c414*);

// USA: func_ov000_0216c414  (semantic: EnqueueEventTwoIntsAndScaledFloat_0216c414)
extern "C" ARM int func_ov000_0216c414(struct Variant02030b0c* obj) {
    struct Event0216c414* e = (struct Event0216c414*)data_ov000_02184264.allocator->Allocate(0x10);
    e->type = 0;
    e->field4 = 0;
    e->type = 0x64;
    e->field8 = (unsigned short)_ZNK6Script9Parameter5ToIntEv(obj);
    e->fielda = (unsigned short)(int)(_ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)obj + 8)) * 4096.0f);
    e->fieldc = (unsigned short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)obj + 0x10));
    func_ov000_02169b78(e);
    return 1;
}
