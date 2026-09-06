#include <globaldefs.h>

struct Obj0217f248 { char pad[0xc]; void* fieldC; };

extern "C" void func_ov003_0216d53c(void*);

// USA: func_ov003_0217f248
ARM void CallIfFieldCSet_0217f248(struct Obj0217f248* obj) {
    if (obj->fieldC) {
        func_ov003_0216d53c(obj->fieldC);
    }
}
