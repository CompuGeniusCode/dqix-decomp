#include <globaldefs.h>

struct Node021d6148 { unsigned int type; Node021d6148* link; };

// USA: func_ov017_021d6148
ARM void SetLinkIfType3_021d6148(Node021d6148* o, unsigned int v) {
	if (o->type == 3) {
		o = o->link;
		o->link = (Node021d6148*)v;
	}
}
