#include <globaldefs.h>

struct CtxA02205c50 {
	unsigned char pad0[0x8];
	unsigned char field8;
	unsigned char pad1[1];
	unsigned short fieldA;
	unsigned char pad2[0xc];
	unsigned short field18;
	unsigned char pad3[2];
	int field1c;
	unsigned char pad4[0x20];
	int field40;
	int field44;
};

struct Ctx02205c50 {
	unsigned char pad0[0xc4];
	struct CtxA02205c50* a;
	unsigned char pad1[0x30];
	int b;
};

struct Obj02205c50 { unsigned char pad[0x64]; struct Ctx02205c50* ctx; };

// USA: func_ov031_02205c50  (semantic: GetDiffAndFields_02205c50)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02205c50(struct Obj02205c50* obj, int* outDiff, unsigned short* outA, unsigned short* out18, int* out1c) {
	struct Ctx02205c50* ctx = obj->ctx;
	struct CtxA02205c50* a = ctx->a;
	int b = ctx->b;
	int diff = a->field44 - b;
	if (diff < 0) {
		goto negative;
	}
	*outA = a->fieldA;
	*out18 = a->field18;
	*out1c = a->field1c;
	*outDiff = diff;
	if (diff != 0) {
		goto ret_sum;
	}
	if (a->field8 == 4) {
		goto ret_sum;
	}
	return 0;
negative:
	*outDiff = -1;
	return 0;
ret_sum:
	return a->field40 + b;
}
