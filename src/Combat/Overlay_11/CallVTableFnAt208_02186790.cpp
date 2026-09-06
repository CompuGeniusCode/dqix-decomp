#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct VTable186790 {
    char pad[0xd0];
    void (*fn)(void*);
};
struct Obj186790 {
    struct VTable186790* vtable;
};

extern "C" struct Obj186790* func_ov023_021f6880(void*, int);

// USA: func_ov011_02186790
ARM int CallVTableFnAt208_02186790(struct TaggedNumber02184c30* tagged) {
    int key = GetTaggedValueAsInt_02184c30(tagged);
    void* base = func_ov017_021b2164();
    void* obj = func_ov011_021849c8(base);
    struct Obj186790* node = func_ov023_021f6880(obj, key);
    if (!node) return 0;
    node->vtable->fn(node);
    return 1;
}
