#include <globaldefs.h>

struct SubObj438_021b204c { unsigned char pad[0x438]; unsigned char b438; };
struct Obj24_021b204c { unsigned char pad[0x24]; SubObj438_021b204c* sub; };

// USA: func_ov017_021b204c
ARM unsigned char GetSubByteField438_021b204c(Obj24_021b204c* obj) {
	SubObj438_021b204c* sub = obj->sub;
	if (sub) return sub->b438;
	return 0;
}
