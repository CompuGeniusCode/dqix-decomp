#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void* obj);

struct Obj02188884 {
    char pad[0x45];
    unsigned char b0:1;
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char b4:1;
    unsigned char b5:1;
    unsigned char b6:1;
    unsigned char b7:1;
};

// USA: func_ov011_02188884  (semantic: SetBit7IfType8_02188884)
extern "C" ARM int func_ov011_02188884(struct TaggedNumber02184c30* a) {
    int key = GetTaggedValueAsInt_02184c30(a);
    int val = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    struct Obj02188884* node = (struct Obj02188884*)func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), key);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 8) return 0;
    node->b7 = val;
    return 1;
}
