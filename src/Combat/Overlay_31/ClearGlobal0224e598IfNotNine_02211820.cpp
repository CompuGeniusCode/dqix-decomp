#include <globaldefs.h>

void ClearGlobal0224e5a4IfNotNine_02211acc(void);

struct GlobalPair0224e598_02211820 {
	int field0;
	int field4;
};
extern GlobalPair0224e598_02211820 data_ov031_0224e598;

// USA: func_ov031_02211820
ARM void ClearGlobal0224e598IfNotNine_02211820(void) {
	ClearGlobal0224e5a4IfNotNine_02211acc();
	if (data_ov031_0224e598.field0 != 9) {
		data_ov031_0224e598.field0 = 0;
		data_ov031_0224e598.field4 = 0;
	}
}
