#include <globaldefs.h>

extern "C" void func_020e5920(void);

// USA: func_0200f29c
ARM int Init_0200f29c(void* obj) {
    void (*volatile p1)(void) = func_020e5920;
    void (*volatile p2)(void) = func_020e5920;
    *(void(**)(void))((char*)obj + 0xc) = p1;
    *(void(**)(void))((char*)obj + 0x10) = p2;
    return 1;
}
