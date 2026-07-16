#include <globaldefs.h>

struct Field0x50dHolder_021dd0ac {
	unsigned char pad0[8];
	unsigned char* ptr;
};

extern Field0x50dHolder_021dd0ac data_ov027_021e33e0;

// USA: func_ov027_021dd0ac
ARM int IsFieldqual1_021dd0ac_021dd0ac(void) {
	return data_ov027_021e33e0.ptr[0x50d] == 1;
}
