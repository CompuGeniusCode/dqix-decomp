#include <globaldefs.h>

struct SubObj439_021b2060 { unsigned char pad[0x439]; unsigned char b439; };
struct Obj24_021b2060 { unsigned char pad[0x24]; SubObj439_021b2060* sub; };

// USA: func_ov017_021b2060
ARM unsigned char GetSubByteField439_021b2060(Obj24_021b2060* obj) {
	SubObj439_021b2060* sub = obj->sub;
	if (sub) return sub->b439;
	return 0;
}
