#include <globaldefs.h>

struct SubObj398_021b2010 { unsigned char pad[0x398]; unsigned char b398; };
struct Obj24_021b2010 { unsigned char pad[0x24]; SubObj398_021b2010* sub; };

// USA: func_ov017_021b2010
ARM unsigned char GetSubByteField398_021b2010(Obj24_021b2010* obj) {
	SubObj398_021b2010* sub = obj->sub;
	if (sub) return sub->b398;
	return 0;
}
