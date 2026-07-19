#include <globaldefs.h>

extern "C" int func_ov031_02223478(int);
extern "C" int func_ov031_0223b61c(int, int*, int);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);

extern "C" void func_ov031_0223b710(int a);

typedef void (*Callback_022234d8)(void*, int, int);

// USA: func_ov031_022234d8  (semantic: CallbackAndForward_022234d8)
extern "C" ARM void func_ov031_022234d8(int a0, Callback_022234d8 cb) {
    int v = func_ov031_02223478(a0);
    int size;
    int ptr = func_ov031_0223b61c(v, &size, 4);
    CleanInvalidateCacheRange((void*)ptr, size);
    cb((void*)ptr, 0, size);
    func_ov031_0223b710(ptr);
}
