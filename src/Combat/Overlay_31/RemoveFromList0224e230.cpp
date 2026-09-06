#include <globaldefs.h>

struct Node02207168 {
	char pad[0x7c];
	int next;
};

extern "C" void* func_ov031_02207120(void* head, Node02207168* item);
extern Node02207168 data_ov031_0224e230;

// USA: func_ov031_02207168
ARM void* RemoveFromList0224e230(Node02207168* item) {
	return func_ov031_02207120(&data_ov031_0224e230, item);
}
