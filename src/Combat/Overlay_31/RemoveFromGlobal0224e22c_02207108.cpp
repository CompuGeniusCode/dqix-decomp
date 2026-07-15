#include <globaldefs.h>

struct Node02207108 {
	char pad[0x7c];
	int next;
};

extern "C" void* func_ov031_02207120(void* head, Node02207108* item);
extern Node02207108 data_ov031_0224e22c;

// USA: func_ov031_02207108
ARM void* RemoveFromGlobal0224e22c_02207108(Node02207108* item) {
	return func_ov031_02207120(&data_ov031_0224e22c, item);
}
