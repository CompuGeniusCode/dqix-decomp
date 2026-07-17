#include <globaldefs.h>

int IsMaskComplementSet_02200754(unsigned int a);
int IsHighNibbleE_02200790(unsigned int v);

struct GlobalStruct0224c980_022007a4 {
	char pad[0x50];
	unsigned int field50;
};

extern GlobalStruct0224c980_022007a4 data_ov031_0224c980;

// USA: func_ov031_022007a4
ARM int IsGlobalMatchOrSpecial_022007a4(unsigned int a) {
	return data_ov031_0224c980.field50 == 0 ||
	       a == data_ov031_0224c980.field50 ||
	       a == 0x7f000001 ||
	       IsMaskComplementSet_02200754(a) != 0 ||
	       IsHighNibbleE_02200790(a) != 0;
}
