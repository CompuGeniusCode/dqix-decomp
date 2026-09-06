#include <globaldefs.h>

void ResetState0205facc(void*);
extern "C" void func_0206ddb8(void*);

// USA: func_02064d1c
ARM void* ResetAndReturn02064d1c(void* obj) {
    func_0206ddb8(obj);
    ResetState0205facc(obj);
    return obj;
}
