#include <globaldefs.h>

int CallHandlerWithGlobalWordFlag(void* obj);
extern "C" int func_020d0dcc(int a1, int a2, int a3, int a4, void* a5, int a6, int a7);

struct Global0211173c { int f0; int f4; };
extern Global0211173c data_0211173c;

// USA: func_020cccf8
ARM int EnqueueCallbackTask020cccf8(int a0, int a1, int a2, int a3) {
    func_020d0dcc(data_0211173c.f4, a2, a1, a3, (void*)CallHandlerWithGlobalWordFlag, a0, 1);
    return 6;
}
