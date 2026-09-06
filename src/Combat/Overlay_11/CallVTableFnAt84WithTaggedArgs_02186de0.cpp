#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct VTable02186de0 {
    char pad[0x54];
    void (*fn)(void*, int);
};
struct Obj02186de0 {
    struct VTable02186de0* vtable;
};
extern "C" struct Obj02186de0* func_ov023_021f6880(void*, int);

// USA: func_ov011_02186de0
ARM int CallVTableFnAt84WithTaggedArgs_02186de0(struct TaggedNumber02184c30* tagged) {
    int key = GetTaggedValueAsInt_02184c30(tagged);
    int val = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 8));
    struct Obj02186de0* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), key);
    if (!node) return 0;
    node->vtable->fn(node, val);
    return 1;
}
