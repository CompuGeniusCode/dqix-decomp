#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(TaggedNumber02184c30*);

extern "C" int func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct Obj02186f74 { char pad[0xc]; unsigned char flags; };
extern "C" struct Obj02186f74* func_ov023_021f6880(void*, int);

// USA: func_ov011_02186f74
ARM int SetFlagBit1IfTagged_02186f74(TaggedNumber02184c30* a) {
    int key = GetTaggedValueAsInt_02184c30(a);
    int val = GetTaggedValueAsInt_02184c30((TaggedNumber02184c30*)((char*)a + 8));
    struct Obj02186f74* node = func_ov023_021f6880(func_ov011_021849c8((void*)func_ov017_021b2164()), key);
    if (!node) return 0;
    if (val != 0) node->flags |= 0x1;
    else node->flags &= ~0x1;
    return 1;
}
