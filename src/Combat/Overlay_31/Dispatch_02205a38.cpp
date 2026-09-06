#include <globaldefs.h>

struct Sub_02205a38 {
	char pad[0xfe];
	signed char flagFE;
};

struct Obj_02205a38 {
	char pad0[0x64];
	Sub_02205a38* field64;
	char pad1[0x73 - 0x68];
	signed char field73;
};

extern "C" int func_ov031_02205ef8(Obj_02205a38* obj, int b, int c, int d, int e, int f);
extern "C" int func_ov031_02205e60(Obj_02205a38* obj);

struct Obj_02205ad4;
int Dispatch_02205ad4(Obj_02205ad4* obj, int b, int c, int d, int e, int f);

// USA: func_ov031_02205a38  (semantic: Dispatch_02205a38)
extern "C" ARM int func_ov031_02205a38(Obj_02205a38* obj, int b, int c, int d, int e, int f, int flags) {
	Sub_02205a38* sub = obj->field64;
	bool hasFlag = ((flags & 2) != 0) && (sub != NULL);
	signed char oldByte;
	if (hasFlag) {
		oldByte = sub->flagFE;
		sub->flagFE = 1;
	}
	int result;
	if (obj->field73 == 1) {
		result = func_ov031_02205ef8(obj, b, c, d, e, f);
	} else {
		result = Dispatch_02205ad4((Obj_02205ad4*)obj, b, c, d, e, f);
		if (result >= 0) {
			func_ov031_02205e60(obj);
		}
	}
	if (hasFlag) {
		sub->flagFE = oldByte;
	}
	return result;
}
