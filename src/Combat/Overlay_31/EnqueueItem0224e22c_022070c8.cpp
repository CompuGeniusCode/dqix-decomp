#include <globaldefs.h>

struct Node022070e0 {
	int next;
};

struct Item022070e0 {
	char pad[0x7c];
	int next;
};

extern "C" void PushFront022070e0(Node022070e0* head, Item022070e0* item);
extern Node022070e0 data_ov031_0224e22c;

// USA: func_ov031_022070c8
ARM void EnqueueItem0224e22c_022070c8(Item022070e0* item) {
	PushFront022070e0(&data_ov031_0224e22c, item);
}
