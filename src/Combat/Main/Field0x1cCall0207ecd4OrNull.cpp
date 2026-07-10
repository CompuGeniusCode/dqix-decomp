#include <globaldefs.h>

struct Obj0207ecd4;
void* ReacquireHandleField0xa6(struct Obj0207ecd4*);

// USA: func_02055624
ARM void* Field0x1cCall0207ecd4OrNull(void* obj) {
    void* x = *(void**)((char*)obj + 0x1c);
    if (x == NULL) return x;
    return ReacquireHandleField0xa6((struct Obj0207ecd4*)x);
}
