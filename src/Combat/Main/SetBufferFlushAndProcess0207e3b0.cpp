#include <globaldefs.h>

struct Stream0207e3b0 { char pad[0x5c]; int field5c; int field60; };

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" void func_0207e44c(struct Stream0207e3b0* obj, int arg);

// USA: func_0207e3b0
ARM void SetBufferFlushAndProcess0207e3b0(struct Stream0207e3b0* obj, int src, int size, int arg) {
    obj->field5c = src;
    obj->field60 = size;
    CleanInvalidateCacheRange((const void*)(obj->field5c), size);
    func_0207e44c(obj, arg);
}
