#include <globaldefs.h>

struct GlobalPair0224e598_02211864 {
	int field0;
	int field4;
};
extern GlobalPair0224e598_02211864 data_ov031_0224e598;

// USA: func_ov031_02211864
ARM void SetGlobal0224e598IfNotNine_02211864(int a, int b) {
	if (b > -10000) b += -10000;
	if (data_ov031_0224e598.field0 != 9) {
		data_ov031_0224e598.field0 = a;
		data_ov031_0224e598.field4 = b;
	}
}
