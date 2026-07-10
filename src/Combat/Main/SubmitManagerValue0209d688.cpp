#include <globaldefs.h>

extern "C" void func_0209f864(void*, int);
extern "C" int func_ov017_021d60f4(void*);
void* GetGlobalManager0209dccc();

// USA: func_0209d688
ARM int SubmitManagerValue0209d688(void* arg) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    func_0209f864(mgr, func_ov017_021d60f4(arg));
    return 1;
}
