#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void* func_ov001_0215ab20(int x);
extern "C" float func_ov017_021d6110(void* obj);
extern "C" void* EnqueueEventType5_0215a3f8(void* target, int a, int b, int c);

// USA: func_ov001_0215c468
ARM int func_ov001_0215c468(char* obj) {
    void* target = func_ov001_0215ab20(func_ov017_021d60f4(obj));
    if (target == NULL) {
        return 0;
    }
    EventVec3 v;
    v.a = (int)(4096.0f * func_ov017_021d6110(obj + 8));
    v.b = (int)(4096.0f * func_ov017_021d6110(obj + 0x10));
    v.c = (int)(4096.0f * func_ov017_021d6110(obj + 0x18));
    EnqueueEventType5_0215a3f8(target, v.a, v.b, v.c);
    return 1;
}
