#include <globaldefs.h>

extern "C" void func_ov031_022183b4(void* self);

typedef void (*Fn0221a4cc)(void*, void*, int);

extern void* data_ov031_0224e69c;
extern int data_ov031_0224a254;

// USA: func_ov031_0221a4cc
ARM void ClearAndNotify_0221a4cc(void) {
    void* ptr = data_ov031_0224e69c;
    if (ptr == 0) {
        return;
    }
    func_ov031_022183b4((char*)ptr + 8);
    ptr = data_ov031_0224e69c;
    Fn0221a4cc fn = *(Fn0221a4cc*)((char*)ptr + 4);
    fn(&data_ov031_0224a254, ptr, 0);
    data_ov031_0224e69c = 0;
}
