#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov017_021d6134(void*, int);
void* GetGlobalManager0209dccc();
struct Context0209fc9c;
int GetIndexedByte0209fc9c(struct Context0209fc9c*, int);

// USA: func_0209da08
ARM int QueryIndexedByte0209da08(void* arg) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    int v = func_ov017_021d60f4(arg);
    int r = GetIndexedByte0209fc9c((struct Context0209fc9c*)mgr, v);
    func_ov017_021d6134((char*)arg + 8, r);
    return 1;
}
