#include <globaldefs.h>

unsigned int DisableSpecificInterrupts(unsigned int mask);
unsigned int EnableSpecificInterrupts(unsigned int mask);

struct Node_0223d8d8 { void* field0; void* field4; };
struct ListHead_0223d8d8 { struct Node_0223d8d8* first; };

// USA: func_ov031_0223d8d8
ARM void InsertListNode_0223d8d8(struct ListHead_0223d8d8* head, struct Node_0223d8d8* node) {
	unsigned int mask = DisableSpecificInterrupts(1);
	head->first->field4 = node;
	node->field0 = head->first;
	node->field4 = head;
	head->first = node;
	EnableSpecificInterrupts(mask);
}
