#include <globaldefs.h>

struct Sub02205c50 {
	char pad0[0x8];
	unsigned char field8;
	char pad2[0x1];
	unsigned short fieldA;
	char pad3[0xc];
	unsigned short field18;
	int field1c;
	char pad4[0x20];
	int field40;
	int field44;
};

struct Ctx02205c50 {
	char pad0[0xc4];
	Sub02205c50* fieldC4;
	char pad1[0x30];
	int field0xf8;
};

struct Obj02205c50 {
	char pad[0x64];
	Ctx02205c50* field64;
};

#pragma optimize_for_size off
// USA: func_ov031_02205c50
ARM int GetDiffOrOffset_02205c50(Obj02205c50* obj, int* out1, unsigned short* out2, unsigned short* out3, int* out4) {
	Ctx02205c50* ctx = obj->field64;
	Sub02205c50* sub = ctx->fieldC4;
	int val = ctx->field0xf8;
	int diff = sub->field44 - val;
	if (diff >= 0) {
		*out2 = sub->fieldA;
		*out3 = sub->field18;
		*out4 = sub->field1c;
		*out1 = diff;
		if (diff != 0 || sub->field8 == 4) {
			return sub->field40 + val;
		}
		return 0;
	}
	*out1 = -1;
	return 0;
}
