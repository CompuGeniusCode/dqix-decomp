#include <globaldefs.h>

struct Sub0218f344 {
	char pad[0xc];
	int val;
};

struct Obj0218f344 {
	char pad1c[0x1c];
	unsigned char state;
	char pad24[0x24 - 0x1d];
	struct Sub0218f344* sub;
};

// USA: func_ov015_0218f344  (semantic: GetSubVal_0218f344)
extern "C" ARM int func_ov015_0218f344(struct Obj0218f344* obj) {
	unsigned char state = obj->state;
	switch (state) {
	case 0:
	case 1:
		return obj->sub->val;
	default:
		return obj->sub->val;
	}
}
