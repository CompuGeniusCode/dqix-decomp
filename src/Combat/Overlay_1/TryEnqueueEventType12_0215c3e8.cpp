#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* p);
extern "C" void* func_ov001_0215ab20(int idx);
void* EnqueueEventType12_0215a5d8(void* ctx);

// USA: func_ov001_0215c3e8
ARM int TryEnqueueEventType12_0215c3e8(void* ctx) {
    int idx = func_ov017_021d60f4(ctx);
    void* node = func_ov001_0215ab20(idx);
    if (node == NULL) return 0;
    EnqueueEventType12_0215a5d8(node);
    return 1;
}
