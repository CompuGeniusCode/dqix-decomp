#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct02184264_0216a1a4 {
	unsigned char pad[8];
	SafeAllocator* alloc;
};
extern struct Struct02184264_0216a1a4 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct VariantNodeTag_0216a1a4 {
	int tag;
	int unused;
	int value;
	unsigned char flag;
};

// USA: func_ov000_0216a1a4  (semantic: AllocateVariantNodeTag_0216a1a4)
extern "C" ARM int func_ov000_0216a1a4(struct Variant02030b0c* v, int count) {
	struct VariantNodeTag_0216a1a4* node = (struct VariantNodeTag_0216a1a4*)data_ov000_02184264.alloc->Allocate(0x10);
	node->tag = 8;
	node->value = _ZNK6Script9Parameter5ToIntEv(v);
	node->flag = 0;
	if (count >= 2) {
		node->flag = (unsigned char)_ZNK6Script9Parameter5ToIntEv(v + 1);
	}
	func_ov000_02169b78(node);
	return 1;
}
