#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(TaggedNumber02184c30*);

extern "C" int func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct VTable02188284 {
    char pad[0xa4];
    void (*fn)(void*, int);
};
struct Obj02188284 {
    struct VTable02188284* vtable;
};
extern "C" struct Obj02188284* func_ov023_021f6880(void*, int);

// USA: func_ov011_02188284
ARM int CallVTableFnAt164WithTaggedArgs_02188284(TaggedNumber02184c30* a) {
    int key = GetTaggedValueAsInt_02184c30(a);
    int val = GetTaggedValueAsInt_02184c30((TaggedNumber02184c30*)((char*)a + 8));
    struct Obj02188284* node = func_ov023_021f6880(func_ov011_021849c8((void*)func_ov017_021b2164()), key);
    if (!node) return 0;
    node->vtable->fn(node, val);
    return 1;
}
