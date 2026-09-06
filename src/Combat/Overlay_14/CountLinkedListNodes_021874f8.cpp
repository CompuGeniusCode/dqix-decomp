#include <globaldefs.h>

struct ListNode021874f8 {
	struct ListNode021874f8* next;
};

struct ListHeadStruct021874f8 {
	char pad[0xb8];
	struct ListNode021874f8* head;
};

// USA: func_ov014_021874f8
ARM short CountLinkedListNodes_021874f8(struct ListHeadStruct021874f8* obj) {
	struct ListNode021874f8* p = obj->head;
	short count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}
