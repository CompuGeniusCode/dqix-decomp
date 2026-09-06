#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct VTable1867cc {
    char pad[0xd4];
    void (*fn)(void*);
};
struct Obj1867cc {
    struct VTable1867cc* vtable;
};

extern "C" struct Obj1867cc* func_ov023_021f6880(void*, int);

// USA: func_ov011_021867cc
ARM int CallVTableFnAt212_021867cc(struct TaggedNumber02184c30* tagged) {
    int key = GetTaggedValueAsInt_02184c30(tagged);
    void* base = func_ov017_021b2164();
    void* obj = func_ov011_021849c8(base);
    struct Obj1867cc* node = func_ov023_021f6880(obj, key);
    if (!node) return 0;
    node->vtable->fn(node);
    return 1;
}
