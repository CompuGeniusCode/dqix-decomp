#include <globaldefs.h>

struct GlobalStruct0224c980_02203120 {
	char pad[0x68];
	unsigned long long seed;
	unsigned long long multiplier;
	unsigned long long increment;
};

extern GlobalStruct0224c980_02203120 data_ov031_0224c980;

// USA: func_ov031_02203120
ARM void UpdateRngState_02203120(void) {
	data_ov031_0224c980.seed = data_ov031_0224c980.increment +
		data_ov031_0224c980.seed * data_ov031_0224c980.multiplier;
}
