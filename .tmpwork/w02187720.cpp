#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct TaggedInput_02187720 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    TaggedNumber02184c30 c;
    TaggedNumber02184c30 d;
};

int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM int func_ov017_0218b5b0(void);
extern "C" ARM void* func_ov023_021fc518(void* obj, void* ctx, int p2, int p3, int p4, unsigned int p5);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM void InitTenAllocatorsAndClearFields_021e4e8c(void* obj);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern void* data_ov023_021ff5b4;

struct LocalBuf_02187720 { char raw[0x1870]; };

// USA: func_ov011_02187720
extern "C" ARM int func_ov011_02187720(struct TaggedInput_02187720* obj) {
    int tag0 = GetTaggedValueAsInt_02184c30(&obj->a);
    int tagB = GetTaggedValueAsInt_02184c30(&obj->b);
    int tagC = GetTaggedValueAsInt_02184c30(&obj->c);
    GetTaggedValueAsInt_02184c30(&obj->d);

    void* node;
    void* ctx = func_ov017_021b2164();
    node = func_ov011_021845f8(ctx, tagB);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();

    unsigned int p5 = *(unsigned int*)((char*)(*(void**)((char*)(func_ov017_0218b5b0() + 0x3000) + 0xb4c)) + 0x4c);

    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x1870);
    if (block == 0) return 0;

    LocalBuf_02187720 local;
    *(void**)&local.raw[0] = &data_ov023_021ff5b4;

    char* blk = local.raw + 0x20;
    char* bufEnd = local.raw + 0x1860;
    do {
        SafeAllocator* p = (SafeAllocator*)(blk + 0x6b8);
        SafeAllocator* end = (SafeAllocator*)(blk + 0x780);
        do {
            p->ResetAllocatorPointer();
            p = (SafeAllocator*)((char*)p + 0x14);
        } while (p < end);
        end->ResetAllocatorPointer();
        InitTenAllocatorsAndClearFields_021e4e8c(blk);
        blk += 0xc20;
    } while (blk < bufEnd);

    memcpy(block, &local, 0x1870);

    if (func_ov023_021fc518(block, ctx, tag0, tagB, tagC, p5) == 0) return 0;

    void* list = func_ov011_021849c8(ctx);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)block);
    return 1;
}
