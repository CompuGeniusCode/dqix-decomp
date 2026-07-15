#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct VTable1883a8 {
    char pad[0x24];
    void (*fn)(void*, int);
};
struct Obj1883a8 {
    struct VTable1883a8* vtable;
};

extern "C" struct Obj1883a8* func_ov023_021f6880(void*, int);

// USA: func_ov011_021883a8
ARM int CallVTableFnAt36_021883a8(struct TaggedNumber02184c30* tagged) {
    int key = GetTaggedValueAsInt_02184c30(tagged);
    void* base = func_ov017_021b2164();
    void* obj = func_ov011_021849c8(base);
    struct Obj1883a8* node = func_ov023_021f6880(obj, key);
    if (!node) return 0;
    node->vtable->fn(node, 1);
    return 1;
}
