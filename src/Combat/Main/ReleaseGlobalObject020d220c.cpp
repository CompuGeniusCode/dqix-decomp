#include <globaldefs.h>
extern "C" int _Z11UnlockMutexP5Mutex(struct RefNode020c80f8*);

extern int data_02112754;

// USA: func_020d220c
// Kept as extern "C" func_020d220c: ResolveOffsetOrPointerEntry references this symbol.
extern "C" ARM void func_020d220c(void) {
    _Z11UnlockMutexP5Mutex((struct RefNode020c80f8*)(&data_02112754));
}
