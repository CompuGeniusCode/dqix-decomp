#include <globaldefs.h>

struct ListNode0220713c { unsigned char pad[0x7c]; ListNode0220713c* next; };
struct ListHead0220713c { ListNode0220713c* head; };

// USA: func_ov031_0220713c  (semantic: FindNodeLink_0220713c)
extern "C" ARM ListNode0220713c** func_ov031_0220713c(ListHead0220713c* list, ListNode0220713c* target) {
	ListNode0220713c* node = list->head;
	ListNode0220713c** link = (ListNode0220713c**)list;
	if (node != NULL) {
		do {
			if (node == target) return link;
			link = &node->next;
			node = node->next;
		} while (node != NULL);
	}
	return NULL;
}
