#include <globaldefs.h>

struct Obj0217f218 { char pad[0xc]; void* fieldC; };

extern "C" void func_ov003_0216d468(void*);

// USA: func_ov003_0217f218
ARM void CallIfFieldCSet_0217f218(struct Obj0217f218* obj) {
    if (obj->fieldC) {
        func_ov003_0216d468(obj->fieldC);
    }
}
