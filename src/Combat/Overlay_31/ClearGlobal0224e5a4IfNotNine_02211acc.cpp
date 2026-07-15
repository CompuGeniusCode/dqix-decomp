#include <globaldefs.h>

struct GlobalPair02211acc {
	int field0;
	int field4;
};
extern GlobalPair02211acc data_ov031_0224e5a4;

// USA: func_ov031_02211acc
ARM void ClearGlobal0224e5a4IfNotNine_02211acc(void) {
	if (data_ov031_0224e5a4.field0 != 9) {
		data_ov031_0224e5a4.field0 = 0;
		data_ov031_0224e5a4.field4 = 0;
	}
}
