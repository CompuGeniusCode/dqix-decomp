#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" char* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d612c(void* obj);
extern "C" int func_ov017_021d60f4(void* a);
extern SafeAllocator* data_ov001_021658b8[8];
extern char strDataStr_02165745;

struct ListNode_021612c8 {
	char pad[0x28];
	struct ListNode_021612c8* next;
};
struct Container_021612c8 {
	char pad[0xd4];
	struct ListNode_021612c8* head;
};

// Handler for event script opcode 0x236: the table entry at 0x02165528 pairs that id with this
// address, and the arguments arrive through the accessors the neighbouring handlers use --
// func_ov017_021d612c, a bare *(void**)(obj+4), and func_ov017_021d60f4, which unpacks a script
// int/float tagged union. The node it allocates carries "data/<name>", a kind byte and a task id
// preset to -1, and goes on the tail of the list at +0xd4 of the event object; func_ov001_02155bb8
// walks that list and polls BackgroundLoader::GetTaskStatus on that id, so the node is a load.
extern "C" ARM int EventScriptQueueDataFileRequest(void* self) {
	struct ListNode_021612c8* newObj;
	struct Container_021612c8* c;
	char* base = func_ov017_0218b5b0();
	c = *(struct Container_021612c8**)(base + 0x3000 + 0x734);
	SafeAllocator* allocator = data_ov001_021658b8[0];
	newObj = (struct ListNode_021612c8*)allocator->Allocate(0x30);
	*(unsigned char*)newObj = 0;
	memset((char*)newObj + 0x1, 0, 0x22);
	*(int*)((char*)newObj + 0x24) = -1;
	*(int*)((char*)newObj + 0x28) = 0;
	*(unsigned char*)((char*)newObj + 0x2c) = 0;
	int idx = func_ov017_021d612c(self);
	sprintf((char*)newObj + 0x1, &strDataStr_02165745, idx);
	*(unsigned char*)newObj = (unsigned char)func_ov017_021d60f4((char*)self + 0x8);
	if (c->head == 0) {
		c->head = newObj;
	} else {
		struct ListNode_021612c8* node = c->head;
		while (node->next != 0) {
			node = node->next;
		}
		node->next = newObj;
	}
	return 1;
}
