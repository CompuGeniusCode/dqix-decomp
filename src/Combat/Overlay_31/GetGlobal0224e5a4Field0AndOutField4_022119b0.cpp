#include <globaldefs.h>

struct GlobalPair022119b0 {
	int field0;
	int field4;
};
extern GlobalPair022119b0 data_ov031_0224e5a4;

// USA: func_ov031_022119b0
ARM int GetGlobal0224e5a4Field0AndOutField4_022119b0(int *out) {
	if (out != 0) {
		*out = data_ov031_0224e5a4.field4;
	}
	return data_ov031_0224e5a4.field0;
}
