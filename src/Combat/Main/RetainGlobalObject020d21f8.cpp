#include <globaldefs.h>

extern "C" int _Z9LockMutexP5Mutex(void*);
extern int data_02112754;

// USA: func_020d21f8
// Kept as extern "C" func_020d21f8: ResolveOffsetOrPointerEntry references this symbol.
extern "C" ARM void func_020d21f8(void) {
    _Z9LockMutexP5Mutex(&data_02112754);
}
