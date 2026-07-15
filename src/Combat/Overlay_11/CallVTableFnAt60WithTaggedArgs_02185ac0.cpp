#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct VTable02185ac0 {
    char pad[0x3c];
    void (*fn)(void*, int);
};
struct Obj02185ac0 {
    struct VTable02185ac0* vtable;
};
extern "C" struct Obj02185ac0* func_ov023_021f6880(void*, int);

// USA: func_ov011_02185ac0
ARM int CallVTableFnAt60WithTaggedArgs_02185ac0(struct TaggedNumber02184c30* tagged) {
    int key = GetTaggedValueAsInt_02184c30(tagged);
    int val = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 8));
    struct Obj02185ac0* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), key);
    if (!node) return 0;
    node->vtable->fn(node, val);
    return 1;
}
