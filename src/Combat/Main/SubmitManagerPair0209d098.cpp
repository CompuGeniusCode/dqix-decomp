#include <globaldefs.h>

extern "C" void func_0209ee34(void*, int, int);
extern "C" int func_ov017_021d60f4(void*);
void* GetGlobalManager0209dccc();

// USA: func_0209d098
ARM int SubmitManagerPair0209d098(char* arg) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(arg);
    int b = func_ov017_021d60f4(arg + 8);
    func_0209ee34(mgr, a, b);
    return 1;
}
