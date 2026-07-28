#include <globaldefs.h>

extern int data_020eed28;

typedef int (*Fn020019ac)(void*, void*);

// USA: func_020019ac  (semantic: CallStoredHandlerFn020019ac)
extern "C" ARM int func_020019ac(void* a, void* b) {
    void* p = *(void**)((char*)&data_020eed28 + 8);
    Fn020019ac fn = *(Fn020019ac*)((char*)p + 4);
    return fn(a, b);
}
