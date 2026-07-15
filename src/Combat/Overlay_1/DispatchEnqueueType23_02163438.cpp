#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void* func_ov001_0215ab20(int t);
void* EnqueueEventType23_0215a69c(void* ctx, int a);

// USA: func_ov001_02163438
ARM int DispatchEnqueueType23_02163438(void* obj) {
    int t = func_ov017_021d60f4(obj);
    void* ctx = func_ov001_0215ab20(t);
    if (ctx == NULL) {
        return 0;
    }
    int a = func_ov017_021d60f4((char*)obj + 0x8);
    EnqueueEventType23_0215a69c(ctx, a);
    return 1;
}
