#include <globaldefs.h>

void* GetGlobalManager0209dccc();
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209fe08(void*, int);

// USA: func_0209db28
ARM int StoreValueInManager0209db28(void* arg) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    func_0209fe08(mgr, func_ov017_021d60f4(arg));
    return 1;
}
