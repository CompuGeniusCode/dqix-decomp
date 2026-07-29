#include <globaldefs.h>

extern "C" void func_020e5920();

struct CallbackPair_0200f29c { char pad[0xc]; void (*a)(); void (*b)(); };

// USA: func_0200f29c
ARM int RegisterInitCallbackPair_0200f29c(CallbackPair_0200f29c* obj) {
    obj->a = func_020e5920;
    obj->b = (void(*)())(void*)func_020e5920;
    return 1;
}
