#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct TaggedInput02187e20 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
};

int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM int func_ov004_02167820(void* self, void* param1, int param2, int param3);
void* ResetAndReturnSelf020dfc2c(void* p);
void InitStruct0205a444(char* obj);
void EmptyDestructor0205a494(void* obj);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern int data_ov004_021705f8;

struct Buf02187e20 {
    void* vtable;
    char pad0[0x20 - 4];
    SafeAllocator alloc;
    char state[0x94 - 0x34];
    char sub[0x118 - 0x94];
};

// USA: func_ov011_02187e20
extern "C" ARM int func_ov011_02187e20(struct TaggedInput02187e20* obj) {
    int tag0 = GetTaggedValueAsInt_02184c30(&obj->a);
    int tag8 = GetTaggedValueAsInt_02184c30(&obj->b);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x118);
    if (block == 0) return 0;

    struct Buf02187e20 local;
    local.vtable = &data_ov004_021705f8;
    local.alloc.ResetAllocatorPointer();
    char* base = local.state;
    ResetAndReturnSelf020dfc2c(base + 4);
    InitStruct0205a444(base + 0x60);
    memcpy(block, &local, sizeof(Buf02187e20));

    if (func_ov004_02167820(block, ctx, tag0, tag8) == 0) {
        EmptyDestructor0205a494(local.sub);
        return 0;
    }

    void* list = func_ov011_021849c8(ctx);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)block);
    EmptyDestructor0205a494(local.sub);
    return 1;
}
