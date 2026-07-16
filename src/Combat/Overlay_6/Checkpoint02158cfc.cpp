#include <globaldefs.h>

struct Node02158cfc { char pad[0x1c]; Node02158cfc *next; };
struct Cont02158cfc { char pad[0x2c]; Node02158cfc *head; Node02158cfc *checkpointOut; };

// USA: func_ov006_02158cfc
ARM void Checkpoint02158cfc(Cont02158cfc *obj, Node02158cfc *target) {
	Node02158cfc *node = obj->head;
	Node02158cfc *checkpoint = node;
	signed char idx = 0;
	while (node) {
		if (idx % 16 == 0) { checkpoint = node; idx = 0; }
		if (node == target) break;
		idx++;
		node = node->next;
	}
	obj->checkpointOut = checkpoint;
}
