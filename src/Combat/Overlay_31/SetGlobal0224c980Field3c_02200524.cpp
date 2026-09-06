#include <globaldefs.h>

struct GlobalStruct0224c980_02200524 {
	char pad[0x3c];
	int field3c;
};

extern GlobalStruct0224c980_02200524 data_ov031_0224c980;

// USA: func_ov031_02200524
ARM void SetGlobal0224c980Field3c_02200524(int v) {
	data_ov031_0224c980.field3c = v;
}
