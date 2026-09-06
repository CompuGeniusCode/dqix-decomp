#include <globaldefs.h>

int IsSpecialOrMaskMatch_022006f0(int a);

struct GlobalStruct0224c980_02200730 {
	char pad[0x2c];
	int field2c;
};

extern GlobalStruct0224c980_02200730 data_ov031_0224c980;

// USA: func_ov031_02200730  (semantic: SelectFieldOrValue_02200730)
extern "C" ARM int func_ov031_02200730(int a) {
	int result = a;
	if (IsSpecialOrMaskMatch_022006f0(a) == 0) {
		result = data_ov031_0224c980.field2c;
	}
	return result;
}
