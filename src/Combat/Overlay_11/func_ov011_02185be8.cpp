#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct TaggedInput_02185be8 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    int mode;
    int extra;
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

struct Buf02185be8 {
    void* vtable;
    char pad[0x24 - 4];
    char sub[0x88 - 0x24];
};

// USA: func_ov011_02185be8
extern "C" ARM int func_ov011_02185be8(struct TaggedInput_02185be8* obj) {
    int tag0 = GetTaggedValueAsInt_02184c30(&obj->a);
    int tag8 = GetTaggedValueAsInt_02184c30(&obj->b);

    int flag;
    if (obj->mode == 2) flag = obj->extra;
    else flag = 0;
    if (flag == 0) return 0;

    int tag18 = GetTaggedValueAsInt_02184c30(&obj->c);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x88);
    if (block == 0) return 0;

    struct Buf02185be8 local;
    InitObjWithVTable_02185ce0(&local);
    memcpy(block, &local, sizeof(Buf02185be8));

    if (func_ov023_021fa760(block, ctx, tag0, tag8, 0, flag, tag18) == 0) {
        EmptyDestructor0205a494(local.sub);
        return 0;
    }

    void* list = func_ov011_021849c8(ctx);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)block);
    EmptyDestructor0205a494(local.sub);
    return 1;
}
