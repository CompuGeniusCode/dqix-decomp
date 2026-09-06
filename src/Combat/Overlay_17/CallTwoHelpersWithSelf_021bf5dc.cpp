#include <globaldefs.h>

extern "C" void func_ov017_021bff2c(void*);
extern "C" void func_ov017_021bf490(void*);

// USA: func_ov017_021bf5dc
ARM void CallTwoHelpersWithSelf_021bf5dc(void* obj) {
    func_ov017_021bff2c(obj);
    func_ov017_021bf490(obj);
}
