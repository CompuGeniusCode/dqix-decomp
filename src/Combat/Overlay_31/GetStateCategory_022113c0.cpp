#include <globaldefs.h>

struct StateObj022113c0 {
	int field0;
};

extern StateObj022113c0* data_ov031_0224e590;

// USA: func_ov031_022113c0
ARM int GetStateCategory_022113c0(void) {
	StateObj022113c0* p = data_ov031_0224e590;
	if (p == NULL) return 0;
	switch (p->field0) {
	case 0:
		return 0;
	case 1:
		return 0;
	case 2:
		return 1;
	case 3:
		return 1;
	default:
		return 0;
	}
}
