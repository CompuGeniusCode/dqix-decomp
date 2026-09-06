#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(TaggedNumber02184c30*);
struct TaggedNumber02184c4c;
extern float GetTaggedValueAsFloat_02184c4c(TaggedNumber02184c4c*);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct VTable0218515c { char pad[0x1c]; void (*fn)(void*, int*); };
struct Obj0218515c { struct VTable0218515c* vtable; };
extern "C" struct Obj0218515c* func_ov023_021f6880(void*, int);

// USA: func_ov011_0218515c
ARM int DispatchVTableFn28WithFixedArgs_0218515c(TaggedNumber02184c30* a) {
    int key = GetTaggedValueAsInt_02184c30(a);
    int args[3];
    args[0] = (int)(4096.0f * GetTaggedValueAsFloat_02184c4c((TaggedNumber02184c4c*)((char*)a + 8)));
    args[1] = (int)(4096.0f * GetTaggedValueAsFloat_02184c4c((TaggedNumber02184c4c*)((char*)a + 0x10)));
    args[2] = 0;
    struct Obj0218515c* node = func_ov023_021f6880(func_ov011_021849c8((void*)func_ov017_021b2164()), key);
    if (!node) return 0;
    node->vtable->fn(node, args);
    return 1;
}
