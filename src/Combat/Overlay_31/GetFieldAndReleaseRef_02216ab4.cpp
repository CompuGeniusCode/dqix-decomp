#include <globaldefs.h>

struct Struct0224e5e8_02216ab4 {
	char pad[8];
	void *field8;
};
extern struct Struct0224e5e8_02216ab4 data_ov031_0224e5e8;

extern "C" void* func_020c8074(void *node);

struct RefNode020c80f8;
void ReleaseNodeRef020c80f8(struct RefNode020c80f8 *node);

// USA: func_ov031_02216ab4
ARM int GetFieldAndReleaseRef_02216ab4(void) {
	void *base = data_ov031_0224e5e8.field8;
	if (base == 0) return 0x16;
	void *node = (char*)base + 0x1000 + 0x3d8;
	func_020c8074(node);
	base = data_ov031_0224e5e8.field8;
	node = (char*)base + 0x1000 + 0x3d8;
	int r4 = *(int*)((char*)base + 0x1000 + 0x4);
	ReleaseNodeRef020c80f8((struct RefNode020c80f8*)node);
	return r4;
}
