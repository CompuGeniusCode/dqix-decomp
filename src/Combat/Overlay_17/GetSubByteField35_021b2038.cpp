#include <globaldefs.h>

struct SubObj35_021b2038 { unsigned char pad[0x35]; unsigned char b35; };
struct Obj24_021b2038 { unsigned char pad[0x24]; SubObj35_021b2038* sub; };

// USA: func_ov017_021b2038
ARM unsigned char GetSubByteField35_021b2038(Obj24_021b2038* obj) {
	SubObj35_021b2038* sub = obj->sub;
	if (sub) return sub->b35;
	return 0;
}
