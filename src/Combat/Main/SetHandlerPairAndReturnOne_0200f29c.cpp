#include <globaldefs.h>

extern "C" void func_020e5920(void);

struct Obj0200f29c { char pad[0xc]; void (*a)(void); void (*b)(void); };

// SKIP attempt func_0200f29c: target loads the SAME function-pointer constant
// (func_020e5920) from TWO separate pool words (ldr r2,.L1; ldr r1,.L2) and
// stores each once; every C form tried (direct double-assign, cast-barrier
// pointer arithmetic, volatile destination fields, two named locals) gets
// CSE'd by mwcc into a single "ldr r1,[pc,#N]" reused for both stores (8 bytes
// / 1 instr + 1 pool word short). No barrier found that defeats the constant
// CSE without inline asm. NOT a match, no // USA: tag.
ARM int SetHandlerPairAndReturnOne_0200f29c(Obj0200f29c* obj) {
    void (*h1)(void) = func_020e5920;
    void (*h2)(void) = func_020e5920;
    obj->a = h1;
    obj->b = h2;
    return 1;
}
