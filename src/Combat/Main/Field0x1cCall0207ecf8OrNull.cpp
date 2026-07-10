#include <globaldefs.h>

struct Obj0207ecf8;
void* ReacquireHandleField0xa4(struct Obj0207ecf8*);

// USA: func_0205560c
ARM void* Field0x1cCall0207ecf8OrNull(void* obj) {
    void* x = *(void**)((char*)obj + 0x1c);
    if (x == NULL) return x;
    return ReacquireHandleField0xa4((struct Obj0207ecf8*)x);
}
