#include <globaldefs.h>

struct Obj02205194 {
	unsigned char pad[0x64];
	int field64;
	int field68;
};

// USA: func_ov031_02205194
ARM int GetField64OrField68_02205194(struct Obj02205194* obj) {
	int v = obj->field64;
	if (v == 0) v = obj->field68;
	return v;
}
