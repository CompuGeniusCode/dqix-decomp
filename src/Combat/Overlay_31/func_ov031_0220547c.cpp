#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Memory.h"

extern "C" ARM int func_ov031_0220547c(void* a0);
extern "C" ARM void func_ov031_02205524(void* a0, void* a1);
extern "C" ARM void func_ov031_022070c8(void* a0);

typedef void* (*AllocFn022496a4)(int size);
struct Allocator022496a4 { char pad[0x18]; AllocFn022496a4 Alloc; };
extern Allocator022496a4* data_ov031_022496a4;

// USA: func_ov031_02205414
extern "C" ARM void* func_ov031_02205414(void* a0) {
    int size = func_ov031_0220547c(a0);
    void* p;
    int state = DisableIRQInterrupts();
    p = data_ov031_022496a4->Alloc(size);
    if (p != NULL) {
        VectorizedMemset(p, 0, size);
        func_ov031_02205524(p, a0);
        func_ov031_022070c8(p);
    }
    SetIRQInterruptState(state);
    return p;
}
