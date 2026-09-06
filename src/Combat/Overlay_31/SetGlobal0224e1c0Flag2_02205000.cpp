#include <globaldefs.h>

struct Obj0224e1c0 {
	char pad[8];
	int field8;
};

extern Obj0224e1c0 data_ov031_0224e1c0;

// USA: func_ov031_02205000
ARM void SetGlobal0224e1c0Flag2_02205000(void) {
	data_ov031_0224e1c0.field8 |= 0x2;
}
