#include <globaldefs.h>

struct Obj0207e2e0;
void ReleaseHandlesAndReset0207e2e0(struct Obj0207e2e0*);

// USA: func_0207e250
ARM void* ResetStructReturnSelf(void* obj) {
    ReleaseHandlesAndReset0207e2e0((struct Obj0207e2e0*)obj);
    return obj;
}
