#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct TaggedInput02188658 {
    TaggedNumber02184c30 tag0;
    TaggedNumber02184c30 tag8;
    int mode1;
    int extra1;
    int mode2;
    int extra2;
    TaggedNumber02184c30 tag20;
    TaggedNumber02184c30 tag28;
    TaggedNumber02184c30 tag30;
};

int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM int func_ov023_021f745c(void* buf, void* obj, int arg2, int arg3, int p5, int p6, int p7, int p8, int p9);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov023_021fe4f0;

struct Buf02188658 { void* magic; char pad[0x54 - 4]; };

// USA: func_ov011_02188658  (semantic: AllocateAndQueueTaggedEvent2_02188658)
extern "C" ARM int func_ov011_02188658(struct TaggedInput02188658* obj) {
    int tag0 = GetTaggedValueAsInt_02184c30(&obj->tag0);
    int tag8 = GetTaggedValueAsInt_02184c30(&obj->tag8);
    int p5;
    if (obj->mode1 == 2) p5 = obj->extra1;
    else p5 = 0;
    if (p5 == 0) return 0;

    int p6;
    if (obj->mode2 == 2) p6 = obj->extra2;
    else p6 = 0;
    if (p6 == 0) return 0;

    int tag20 = GetTaggedValueAsInt_02184c30(&obj->tag20);
    int tag28 = GetTaggedValueAsInt_02184c30(&obj->tag28);
    int tag30 = GetTaggedValueAsInt_02184c30(&obj->tag30);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x54);
    if (block == 0) return 0;

    struct Buf02188658 local;
    local.magic = &data_ov023_021fe4f0;
    memcpy(block, &local, sizeof(Buf02188658));

    if (func_ov023_021f745c(block, ctx, tag0, tag8, p5, p6, tag20, tag28, tag30) == 0) return 0;

    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(ctx), (struct ListNode_021f67ac*)block);
    return 1;
}
