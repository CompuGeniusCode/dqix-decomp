#include <globaldefs.h>

extern "C" void func_ov017_021bb27c(void*);
extern "C" void func_ov017_021bb108(void*);

// USA: func_ov017_021bb8d8
ARM void CallTwoHelpers_021bb8d8(void* obj) {
    func_ov017_021bb27c(obj);
    func_ov017_021bb108(obj);
}
