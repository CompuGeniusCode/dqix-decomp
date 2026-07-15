#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(TaggedNumber02184c30*);

extern "C" int func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct VTable021883e8 {
    char pad[0x34];
    void (*fn)(void*, int);
};
struct Obj021883e8 {
    struct VTable021883e8* vtable;
};
extern "C" struct Obj021883e8* func_ov023_021f6880(void*, int);

// USA: func_ov011_021883e8
ARM int CallVTableFnAt52WithTaggedArgs_021883e8(TaggedNumber02184c30* a) {
    int key = GetTaggedValueAsInt_02184c30(a);
    int val = GetTaggedValueAsInt_02184c30((TaggedNumber02184c30*)((char*)a + 8));
    struct Obj021883e8* node = func_ov023_021f6880(func_ov011_021849c8((void*)func_ov017_021b2164()), key);
    if (!node) return 0;
    node->vtable->fn(node, val);
    return 1;
}
