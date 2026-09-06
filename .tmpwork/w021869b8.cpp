#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct TaggedInput_021869b8 {
    TaggedNumber02184c30 a; // 0
    TaggedNumber02184c30 b; // 8
    TaggedNumber02184c30 c; // 0x10
    TaggedNumber02184c30 d; // 0x18
    TaggedNumber02184c30 e; // 0x20
};

int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM void* func_ov023_021f6880(void** list, int value);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

struct VTable021869b8 {
    char pad[0xe8];
    int (*fn)(void*);
};
struct VNode021869b8 {
    struct VTable021869b8* vtable;
};

extern "C" ARM void* ResetAndReturnSelf020dfc2c(void* p);
extern "C" ARM void* ZeroInitReturn020df80c(void* obj);
extern "C" ARM void InitStruct0205a444(char* obj);
extern "C" ARM void EmptyDestructor0205a494(void* obj);

struct Obj021fbd00;
extern "C" ARM int func_ov023_021fbd00(struct Obj021fbd00* obj, void* ctx, int arg2, int arg3, int arg5, int arg6, unsigned char arg7);

extern void* data_ov023_021ff17c;

struct LocalBuf_021869b8 { char raw[0x7bc]; };

// USA: func_ov011_021869b8
extern "C" ARM int func_ov011_021869b8(struct TaggedInput_021869b8* obj, int count) {
    int tag0 = GetTaggedValueAsInt_02184c30(&obj->a);
    int tagB = GetTaggedValueAsInt_02184c30(&obj->b);
    int tagC = GetTaggedValueAsInt_02184c30(&obj->c);
    int tagD = GetTaggedValueAsInt_02184c30(&obj->d);

    unsigned char flag = 0;
    if (count != 4) {
        flag = (unsigned char)GetTaggedValueAsInt_02184c30(&obj->e);
    }

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tagB);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x7bc);
    if (block == 0) return 0;

    int callResult = 0;
    void* list = func_ov011_021849c8(ctx);
    void* found = func_ov023_021f6880((void**)list, tagD);
    if (found != 0) {
        callResult = ((VNode021869b8*)found)->vtable->fn(found);
    }

    LocalBuf_021869b8 local;
    *(void**)&local.raw[0] = &data_ov023_021ff17c;

    char* body = local.raw + 0x20;
    ((SafeAllocator*)(body + 0x00))->ResetAllocatorPointer();
    ((SafeAllocator*)(body + 0x14))->ResetAllocatorPointer();
    ((SafeAllocator*)(body + 0x28))->ResetAllocatorPointer();
    ResetAndReturnSelf020dfc2c(body + 0x54);
    ZeroInitReturn020df80c(body + 0x6c);
    ZeroInitReturn020df80c(body + 0x7c);
    ResetAndReturnSelf020dfc2c(body + 0x8c);
    ResetAndReturnSelf020dfc2c(body + 0xa4);
    InitStruct0205a444(body + 0x12c);

    memcpy(block, &local, 0x7bc);

    if (func_ov023_021fbd00((struct Obj021fbd00*)block, ctx, tag0, tagB, tagC, callResult, flag) == 0) {
        EmptyDestructor0205a494(&local.raw[0x12c]);
        return 0;
    }

    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)block);
    EmptyDestructor0205a494(&local.raw[0x12c]);
    return 1;
}
