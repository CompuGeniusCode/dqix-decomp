#include <globaldefs.h>

int CallWithZeroZeroD_02207380(int a, int b, int c, int d);

struct Field4Struct022414cc {
	int unk0;
	int field4;
};

// USA: func_ov031_022414cc  (semantic: CallWithZeroZeroDAndCheckField4_022414cc)
extern "C" ARM int func_ov031_022414cc(struct Field4Struct022414cc *obj, int b, int c, int d, int e) {
	int result = CallWithZeroZeroD_02207380(b, c, d, e);
	if (result >= 0) {
		return result;
	}
	if (obj->field4 != 0) {
		return 0xfffffc16;
	}
	if (result == ~0x37) {
		return 0;
	}
	return ~0x3e8;
}
