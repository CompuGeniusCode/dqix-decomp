#include <globaldefs.h>

struct Node022070e0 {
	int next;
};

struct Item022070e0 {
	char pad[0x7c];
	int next;
};

// USA: func_ov031_022070e0
ARM void PushFront022070e0(Node022070e0* head, Item022070e0* item) {
	item->next = head->next;
	head->next = (int)item;
}
