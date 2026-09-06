#include <globaldefs.h>

struct SubObj34_021b2024 { unsigned char pad[0x34]; unsigned char b34; };
struct Obj24_021b2024 { unsigned char pad[0x24]; SubObj34_021b2024* sub; };

// USA: func_ov017_021b2024
ARM unsigned char GetSubByteField34_021b2024(Obj24_021b2024* obj) {
	SubObj34_021b2024* sub = obj->sub;
	if (sub) return sub->b34;
	return 0;
}
