#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

struct TaggedInput02188560 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    int mode1;
    int extra1;
    int mode2;
    int extra2;
    TaggedNumber02184c30 c;
};

extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);

struct Obj0RowEvent021fa298;
int InitEvent4_021fa298(struct Obj0RowEvent021fa298* obj, int p1, int p2, int p3, int p4, int p5, int p6);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern int data_ov024_021fea34;

struct Buf02188560 { void* vtable; char pad[0x30 - 4]; };

// USA: func_ov011_02188560
extern "C" ARM int func_ov011_02188560(struct TaggedInput02188560* obj) {
    int tag0 = GetTaggedValueAsInt_02184c30(&obj->a);
    int tag8 = GetTaggedValueAsInt_02184c30(&obj->b);

    int extra1;
    if (obj->mode1 == 2) extra1 = obj->extra1;
    else extra1 = 0;
    if (extra1 == 0) return 0;

    int extra2;
    if (obj->mode2 == 2) extra2 = obj->extra2;
    else extra2 = 0;
    if (extra2 == 0) return 0;

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    int tag20 = GetTaggedValueAsInt_02184c30(&obj->c);

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x30);
    if (block == 0) return 0;

    struct Buf02188560 local;
    local.vtable = &data_ov024_021fea34;
    memcpy(block, &local, sizeof(Buf02188560));

    if (InitEvent4_021fa298((struct Obj0RowEvent021fa298*)block, (int)ctx, tag0, tag8, extra1, extra2, tag20) == 0) return 0;

    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(ctx), (struct ListNode_021f67ac*)block);
    return 1;
}
