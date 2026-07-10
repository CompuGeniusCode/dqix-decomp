#include <globaldefs.h>

extern "C" void func_0205157c(void*);

// USA: func_02052944
ARM void* CallAndReturnSelf02052944(void* obj) {
    func_0205157c(obj);
    return obj;
}
