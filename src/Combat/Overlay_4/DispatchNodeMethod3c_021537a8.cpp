#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);

struct VTable021537a8 {
    char pad[0x3c];
    int (*fn)(void*, int);
};
struct Obj021537a8 {
    struct VTable021537a8* vtable;
};

// USA: func_ov004_021537a8  (semantic: DispatchNodeMethod3c_021537a8)
extern "C" ARM int func_ov004_021537a8(void* self, int key, int arg) {
    struct Obj021537a8* node = (struct Obj021537a8*)func_ov023_021f6880(func_ov011_021849c8(self), key);
    if (!node) return (int)node;
    return node->vtable->fn(node, arg);
}
