#include <globaldefs.h>

struct NodeWithNext02207120 { char pad[0x7c]; void* next; };
extern "C" void* FindListSlot_0220713c(void* head, void* item);

// USA: func_ov031_02207120
ARM void* RemoveListNode_02207120(void* head, NodeWithNext02207120* item) {
	void** slot = (void**)FindListSlot_0220713c(head, item);
	if (slot != NULL) {
		*slot = item->next;
	}
	return slot;
}
