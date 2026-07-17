#include <globaldefs.h>

struct StateObj02211484 {
	int field0;
	char pad[0xc];
	int field10;
};

extern StateObj02211484* data_ov031_0224e590;

// USA: func_ov031_02211484
ARM int CheckRangeIfStateReady_02211484(int flag, unsigned int val) {
	StateObj02211484* p = data_ov031_0224e590;
	if (p == NULL) return 0;
	if (p->field0 != 2) return 0;
	if (p->field10 != 0) return 0;
	if (flag) {
		if (val < 1 || val > 0xff) return 0;
	} else {
		if (val < 1 || val > 0xf) return 0;
	}
	return 1;
}
