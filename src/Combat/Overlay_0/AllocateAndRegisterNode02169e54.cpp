#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct02184264 {
	unsigned char pad[8];
	SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct Node02169e54 {
	int tag;
};

// USA: func_ov000_02169e54
ARM int AllocateAndRegisterNode02169e54() {
	struct Node02169e54* node = (struct Node02169e54*)data_ov000_02184264.alloc->Allocate(8);
	node->tag = 4;
	func_ov000_02169b78(node);
	return 1;
}
