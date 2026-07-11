#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);
void* GetGlobalManager0209dccc();
struct Context0209fc84;
int GetValueBySelector0209fc84(struct Context0209fc84*, int);

// USA: func_0209d38c
ARM int ForwardSelectorValueToOverlay0209d38c(char* arg) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    int v = GetValueBySelector0209fc84((struct Context0209fc84*)mgr, func_ov017_021d60f4(arg));
    func_ov017_021d6134(arg + 8, v);
    return 1;
}
