#include <globaldefs.h>

struct GlobalStruct0224c980_022006f0 {
	char pad1[0x1c];
	unsigned int field1c;
	char pad2[0x50-0x1c-4];
	unsigned int field50;
};

extern GlobalStruct0224c980_022006f0 data_ov031_0224c980;

// USA: func_ov031_022006f0
ARM int IsSpecialOrMaskMatch_022006f0(int a) {
	int result = 1;
	if (a != -1 && a != 0x7F000001) {
		unsigned int mask = data_ov031_0224c980.field1c;
		if ((a & mask) != (data_ov031_0224c980.field50 & mask)) result = 0;
	}
	return result;
}
