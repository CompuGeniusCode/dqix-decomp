#include <globaldefs.h>

int IsSpecialOrMaskMatch_022006f0(int a);

struct GlobalStruct0224c980_02200754 {
	char pad[0x1c];
	unsigned int field1c;
};

extern GlobalStruct0224c980_02200754 data_ov031_0224c980;

// USA: func_ov031_02200754
ARM int IsMaskComplementSet_02200754(unsigned int a) {
	int result = 0;
	if (IsSpecialOrMaskMatch_022006f0(a) != 0) {
		unsigned int inv = ~data_ov031_0224c980.field1c;
		if (inv == (inv & a)) {
			result = 1;
		}
	}
	return result;
}
