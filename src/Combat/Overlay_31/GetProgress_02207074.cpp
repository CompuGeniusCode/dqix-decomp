#include <globaldefs.h>

struct Inner02207074 {
	char pad[4];
	unsigned short field4;
};

struct SubCtx02207074 {
	char pad[0xf8];
	unsigned int field0xf8;
	char pad2[0x104 - 0xfc];
	Inner02207074* field0x104;
};

struct Obj02207074 {
	char pad[0x44];
	unsigned int field44;
	char pad2[0x64 - 0x48];
	SubCtx02207074* field64;
	char pad3[0x73 - 0x68];
	signed char field73;
};

// USA: func_ov031_02207074
ARM int GetProgress_02207074(Obj02207074* obj) {
	SubCtx02207074* ctx = obj->field64;
	int result = 0;
	if (ctx) {
		signed char f73 = obj->field73;
		if (f73 == 1) {
			Inner02207074* p = ctx->field0x104;
			if (p) result = p->field4;
		} else if (f73 == 0 || f73 == 4) {
			result = obj->field44 - ctx->field0xf8;
		}
	}
	return result;
}
