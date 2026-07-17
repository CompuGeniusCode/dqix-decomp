#include <globaldefs.h>

struct Struct0224e5e8_02217598 {
	char pad[8];
	void *field8;
};
extern struct Struct0224e5e8_02217598 data_ov031_0224e5e8;

extern "C" void* func_020c8074(void *node);

struct RefNode020c80f8;
void ReleaseNodeRef020c80f8(struct RefNode020c80f8 *node);

// USA: func_ov031_02217598
ARM void SetFieldWithRefGuard_02217598(int val) {
	void *base = data_ov031_0224e5e8.field8;
	void *node = (char*)base + 0x1000 + 0x3d8;
	func_020c8074(node);
	base = data_ov031_0224e5e8.field8;
	*(int*)((char*)base + 0x1000 + 0x4) = val;
	base = data_ov031_0224e5e8.field8;
	node = (char*)base + 0x1000 + 0x3d8;
	ReleaseNodeRef020c80f8((struct RefNode020c80f8*)node);
}
