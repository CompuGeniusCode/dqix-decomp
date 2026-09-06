#include <globaldefs.h>

struct Struct02193150 { char pad[0x5c]; short f5c; short f5e; short f60; };

// USA: func_ov015_02193150
ARM void AddToShortField02193150(struct Struct02193150* s, int v) {
	s->f60 = v + s->f5c;
}
