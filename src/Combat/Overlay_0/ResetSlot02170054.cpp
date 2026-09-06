#include <globaldefs.h>

struct State0xc0cc;
void ReinitFieldState0203c0f0(struct State0xc0cc* obj);
extern "C" void func_ov000_0216fe9c(void* obj);

// USA: func_ov000_02170054
ARM void ResetSlot02170054(void* obj) {
    ReinitFieldState0203c0f0((struct State0xc0cc*)((char*)obj + 0x50));
    ReinitFieldState0203c0f0((struct State0xc0cc*)((char*)obj + 0x68));
    func_ov000_0216fe9c((char*)obj + 0x8);
}
