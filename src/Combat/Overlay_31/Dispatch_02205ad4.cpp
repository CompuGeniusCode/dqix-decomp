#include <globaldefs.h>

struct Obj_02205ad4 {
	char pad[0x73];
	signed char field73;
};

extern "C" int func_ov031_02205cc4(Obj_02205ad4* obj, int b, int c, int d, int e);
extern "C" int func_ov031_02205b48(Obj_02205ad4* obj, int b, int c, int d, int e);

// USA: func_ov031_02205ad4
ARM int Dispatch_02205ad4(Obj_02205ad4* obj, int b, int c, int d, int e, int f) {
	if (obj->field73 == 4) {
		return func_ov031_02205cc4(obj, b, c, d, e);
	}
	int result = func_ov031_02205b48(obj, b, c, d, e);
	if (result != -6) {
		return result;
	}
	if ((f & 1) == 0) {
		return result;
	}
	return func_ov031_02205cc4(obj, b, c, d, e);
}
