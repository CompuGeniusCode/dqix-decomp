#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov017_021d6134(void*, int);
void* GetGlobalManager0209dccc();
struct Obj0209fccc;
int GetScaledGrottoValue0209fccc(struct Obj0209fccc*, int);

// USA: func_0209d44c
ARM int QueryScaledGrottoValue0209d44c(void* arg) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    int v = func_ov017_021d60f4(arg);
    int r = GetScaledGrottoValue0209fccc((struct Obj0209fccc*)mgr, v);
    func_ov017_021d6134((char*)arg + 8, r);
    return 1;
}
