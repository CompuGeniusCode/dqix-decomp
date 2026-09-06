#include <globaldefs.h>

struct VTable66bc {
    char pad[0xf0];
    void (*fn)(void*, void*);
};
struct Obj66bc {
    struct VTable66bc* vtable;
};

extern "C" void* func_ov011_021849c8(void*);
extern "C" struct Obj66bc* func_ov023_021f6880(void*, int);

// USA: func_ov023_021f66bc
ARM void CallVTableFnAt240_021f66bc(void* a, int key, void* arg3) {
    void* base = func_ov011_021849c8(a);
    struct Obj66bc* node = func_ov023_021f6880(base, key);
    if (node) node->vtable->fn(node, arg3);
}
