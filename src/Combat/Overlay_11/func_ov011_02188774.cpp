#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct TaggedInput02188774 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    int mode1;
    int extra1;
    int mode2;
    int extra2;
    TaggedNumber02184c30 c;
};

int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
ARM void* InitObjWithVTable_02185ce0(void* obj);
ARM void EmptyDestructor0205a494(void* obj);
extern "C" ARM int func_ov023_021fa760(void* obj, void* ctx, int p2, int p3, int p4, int p5, int p6);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

struct Buf02188774 {
    void* vtable;
    char pad[0x24 - 4];
    char sub[0x88 - 0x24];
};

// USA: func_ov011_02188774
extern "C" ARM int func_ov011_02188774(struct TaggedInput02188774* obj) {
    int tag0 = GetTaggedValueAsInt_02184c30(&obj->a);
    int tag8 = GetTaggedValueAsInt_02184c30(&obj->b);
    int flag1;
    if (obj->mode1 == 2) flag1 = obj->extra1;
    else flag1 = 0;
    if (flag1 == 0) return 0;

    int flag2;
    if (obj->mode2 == 2) flag2 = obj->extra2;
    else flag2 = 0;
    if (flag2 == 0) return 0;

    int tag20 = GetTaggedValueAsInt_02184c30(&obj->c);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x88);
    if (block == 0) return 0;

    struct Buf02188774 local;
    InitObjWithVTable_02185ce0(&local);
    memcpy(block, &local, sizeof(Buf02188774));

    if (func_ov023_021fa760(block, ctx, tag0, tag8, flag1, flag2, tag20) == 0) {
        EmptyDestructor0205a494(local.sub);
        return 0;
    }

    void* list = func_ov011_021849c8(ctx);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)block);
    EmptyDestructor0205a494(local.sub);
    return 1;
}
