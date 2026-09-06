#include <globaldefs.h>

extern "C" void func_0209f030(void*, int, int, int);
extern "C" int func_ov017_021d60f4(void*);
void* GetGlobalManager0209dccc();

// USA: func_0209d150
ARM int SubmitManagerTriple0209d150(char* arg) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(arg);
    int b = func_ov017_021d60f4(arg + 8);
    int c = func_ov017_021d60f4(arg + 0x10);
    func_0209f030(mgr, a, b, c);
    return 1;
}
