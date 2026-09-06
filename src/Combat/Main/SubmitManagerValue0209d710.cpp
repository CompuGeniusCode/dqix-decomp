#include <globaldefs.h>

extern "C" void func_0209fb90(void*, int);
extern "C" int func_ov017_021d60f4(void*);
void* GetGlobalManager0209dccc();

// USA: func_0209d710
ARM int SubmitManagerValue0209d710(void* arg) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    func_0209fb90(mgr, func_ov017_021d60f4(arg));
    return 1;
}
