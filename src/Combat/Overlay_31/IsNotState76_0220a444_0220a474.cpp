#include <globaldefs.h>

struct InnerObj0220a474 {
	unsigned char pad0[0x30];
	unsigned char field30;
	unsigned char field31;
	unsigned char pad2[0x455 - 0x32];
	unsigned char field455;
};

struct ObjA0220a474 {
	unsigned char pad0[0xc];
	InnerObj0220a474* inner;
	unsigned char pad1[0x18 - 0x10];
	unsigned short field18;
	int field1c;
};

extern "C" void func_ov031_02209ff0(ObjA0220a474* obj);
extern "C" int func_ov031_02209b58(ObjA0220a474* obj);
extern "C" void func_ov031_02208f50(InnerObj0220a474* obj);
ARM int IsNotState76_0220a444(int a);
extern "C" void func_ov031_02209e98(ObjA0220a474* obj);
extern "C" void func_ov031_0220a184(ObjA0220a474* obj);
ARM void BuildAndCopyContext_02208ef0(void* ctx);
extern "C" void func_ov031_02207b44(void* obj, int a, int b);

// USA: func_ov031_0220a474
extern "C" ARM int func_ov031_0220a474(ObjA0220a474* obj) {
	InnerObj0220a474* inner = obj->inner;
	func_ov031_02209ff0(obj);
	int state;
	do {
		state = func_ov031_02209b58(obj);
		if (state == 9) return 1;
		if (state == 4) break;
	} while (inner->field31 == 0);

	if (inner->field31 != 0) {
		func_ov031_02208f50(inner);
		if (IsNotState76_0220a444((int)obj) != 0) return 1;
		func_ov031_02209e98(obj);
	} else {
		func_ov031_0220a184(obj);
		BuildAndCopyContext_02208ef0(inner);
		if (inner->field30 != 0) {
			func_ov031_02207b44(inner, obj->field1c, obj->field18);
		}
		func_ov031_02208f50(inner);
		func_ov031_02209e98(obj);
		if (IsNotState76_0220a444((int)obj) != 0) return 1;
	}
	inner->field455 = 8;
	return 0;
}
