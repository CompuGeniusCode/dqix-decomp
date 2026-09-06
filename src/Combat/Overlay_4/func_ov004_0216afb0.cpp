#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void*);
struct Obj021f89f4;
extern "C" void func_ov023_021f89f4(struct Obj021f89f4* obj, void* a1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int flag);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov023_021fe708;

struct Buf0216afb0 { void* magic; char pad[0x50 - 4]; };

// USA: func_ov004_0216afb0  (semantic: AllocateAndDispatchEvent0x192_0216afb0)
extern "C" ARM void func_ov004_0216afb0(void* a1, int p2, int p3, int p4,
    int p5, int p6, int p7, int p8, unsigned char p9) {
    void* buf = func_ov011_021845f8(a1, p3);
    void* block = ((SafeAllocator*)((char*)buf + 4))->Allocate(0x50);
    if (!block) return;

    struct Buf0216afb0 local;
    local.magic = &data_ov023_021fe708;
    memcpy(block, &local, sizeof(Buf0216afb0));

    int flag = 0xf;
    if (p9 == 0) flag = 3;
    func_ov023_021f89f4((struct Obj021f89f4*)block, a1, p2, p3, p4, 0x192, p5, p6, p7, p8, flag);

    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(a1), (struct ListNode_021f67ac*)block);
}
