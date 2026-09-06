#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void func_ov023_021f745c(void* buf, void* obj, int msgId, int p3, void* p4, void* fmt, int p6, int p7, int p8);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov004_02170752;
extern char data_ov004_02170761;
extern char data_ov004_02170770;
extern char data_ov004_02170780;
extern char data_ov004_02170790;
extern char data_ov004_021707a0;
extern char data_ov023_021fe4f0;

struct Buf0216e0c0 { void* magic; char pad[0x54 - 4]; };

// USA: func_ov004_0216e0c0  (semantic: AllocateAndDispatchStatusMessage_0216e0c0)
extern "C" ARM int func_ov004_0216e0c0(void* obj) {
    void* fmt = 0;
    void* p4 = 0;
    unsigned char state = *((unsigned char*)GetBattleStruct() + 0x7f71);
    switch (state) {
        case 0: p4 = &data_ov004_02170752; fmt = &data_ov004_02170761; break;
        case 1: p4 = &data_ov004_02170770; fmt = &data_ov004_02170780; break;
        case 2: p4 = &data_ov004_02170790; fmt = &data_ov004_021707a0; break;
    }

    void* buf = func_ov011_021845f8(obj, 3);
    if (!buf) {
        return 0;
    }
    ((SafeAllocator*)((char*)buf + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)buf + 4))->Allocate(0x54);
    if (!block) {
        return 0;
    }

    struct Buf0216e0c0 local;
    local.magic = &data_ov023_021fe4f0;
    memcpy(block, &local, sizeof(Buf0216e0c0));

    func_ov023_021f745c(block, obj, 0x69, 3, p4, fmt, 1, 2, 0);

    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(obj), (struct ListNode_021f67ac*)block);
    return 0;
}
