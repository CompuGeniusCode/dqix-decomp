#include <globaldefs.h>

struct Struct022407e4;
extern int IsFieldCLessOrEqual_022407e4(struct Struct022407e4* obj, unsigned int val);
extern "C" int func_ov031_02241480(void*, int, int, int, int);

struct Sub02240820 { unsigned char pad[0xc]; int fieldC; unsigned char pad2[8]; int field18; };
struct Obj02240820 { unsigned char pad[0x30]; struct Sub02240820* sub; };

// USA: func_ov031_02240820  (semantic: CheckFieldCAndCallField30_02240820)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02240820(struct Obj02240820* obj, int b, int c, int d, int e) {
	struct Sub02240820* sub = obj->sub;
	if (IsFieldCLessOrEqual_022407e4((struct Struct022407e4*)sub, c)) {
		return -1003;
	}
	int rem = sub->fieldC - c;
	if (d <= rem) rem = d;
	return func_ov031_02241480(obj, b, sub->field18 + c, rem, e);
}
