#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);

struct EventCtx0216ba68 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216ba68 data_ov000_02184264;

struct Event0216ba68 {
    int type;
    int field4;
    unsigned short field8;
    unsigned short fielda;
};

extern "C" void func_ov000_02169b78(struct Event0216ba68*);

// USA: func_ov000_0216ba68
ARM int EnqueueEventTwoShorts_0216ba68(struct Variant02030b0c* obj) {
    struct Event0216ba68* e = (struct Event0216ba68*)data_ov000_02184264.allocator->Allocate(0xc);
    if (e == 0) return 0;
    e->type = 0;
    e->field4 = 0;
    e->type = 0x45;
    e->field8 = (unsigned short)_ZNK6Script9Parameter5ToIntEv(obj);
    e->fielda = (unsigned short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)obj + 8));
    func_ov000_02169b78(e);
    return 1;
}
