#include <globaldefs.h>

struct SubObj44_021b1fe8 { unsigned char pad[0x44]; unsigned char b44; };
struct Obj24_021b1fe8 { unsigned char pad[0x24]; SubObj44_021b1fe8* sub; };

// USA: func_ov017_021b1fe8
ARM unsigned char GetSubByteField44_021b1fe8(Obj24_021b1fe8* obj) {
	SubObj44_021b1fe8* sub = obj->sub;
	if (sub) return sub->b44;
	return 0;
}
