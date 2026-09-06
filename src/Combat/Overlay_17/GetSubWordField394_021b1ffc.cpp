#include <globaldefs.h>

struct SubObj394_021b1ffc { unsigned char pad[0x394]; int w394; };
struct Obj24_021b1ffc { unsigned char pad[0x24]; SubObj394_021b1ffc* sub; };

// USA: func_ov017_021b1ffc
ARM int GetSubWordField394_021b1ffc(Obj24_021b1ffc* obj) {
	SubObj394_021b1ffc* sub = obj->sub;
	if (sub) return sub->w394;
	return 0;
}
