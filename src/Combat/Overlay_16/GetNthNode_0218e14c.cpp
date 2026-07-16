#include <globaldefs.h>

struct Node0218e14c {
	char pad[0x18];
	Node0218e14c* next;
};

// USA: func_ov016_0218e14c
ARM void* GetNthNode_0218e14c(Node0218e14c** list, int n) {
	Node0218e14c* node = *list;
	while (n > 0) {
		if (node == NULL) return NULL;
		node = node->next;
		n--;
	}
	return node;
}
