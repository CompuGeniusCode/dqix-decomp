#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209f24c(void*, int, int);
void* GetGlobalManager0209dccc();

// USA: func_0209d510
ARM int InvokeManagerWithParams0209d510(void* arg) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(arg);
    int b = func_ov017_021d60f4((char*)arg + 8);
    func_0209f24c(mgr, a, b);
    return 1;
}
