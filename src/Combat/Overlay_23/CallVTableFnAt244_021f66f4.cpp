#include <globaldefs.h>

struct VTable66f4 {
    char pad[0xf4];
    void (*fn)(void*, void*);
};
struct Obj66f4 {
    struct VTable66f4* vtable;
};

extern "C" void* func_ov011_021849c8(void*);
extern "C" struct Obj66f4* func_ov023_021f6880(void*, int);

// USA: func_ov023_021f66f4
ARM void CallVTableFnAt244_021f66f4(void* a, int key, void* arg3) {
    void* base = func_ov011_021849c8(a);
    struct Obj66f4* node = func_ov023_021f6880(base, key);
    if (node) node->vtable->fn(node, arg3);
}
