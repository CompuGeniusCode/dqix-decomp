#include <globaldefs.h>

struct ListNode021dadac {
	char pad[0x4bc];
	struct ListNode021dadac *next;
};

struct ListRoot021dadac {
	char pad[0x18];
	struct ListNode021dadac *head;
};

extern struct ListRoot021dadac data_ov027_021dd940;

// USA: func_ov027_021dadac
ARM void EnqueueNode_021dadac(struct ListNode021dadac *node) {
	struct ListNode021dadac *cur = data_ov027_021dd940.head;
	if (cur == NULL) {
		data_ov027_021dd940.head = node;
	} else {
		struct ListNode021dadac *next = cur->next;
		if (next != NULL) {
			do {
				cur = next;
				next = cur->next;
			} while (next != NULL);
		}
		cur->next = node;
	}
	node->next = NULL;
}
