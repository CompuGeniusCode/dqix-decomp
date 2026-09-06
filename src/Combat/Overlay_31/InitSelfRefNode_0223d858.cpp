#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(int size, int align);

struct Node0223d858 {
	int field0;
	void* field4;
	void* field8;
	int fieldc;
};

// USA: func_ov031_0223d858
ARM Node0223d858* InitSelfRefNode_0223d858(void) {
	Node0223d858* self = (Node0223d858*)func_ov031_0223cf4c(0x10, 0x4);
	self->field0 = 0;
	self->field4 = &self->field8;
	self->field8 = self;
	self->fieldc = 0;
	return self;
}
