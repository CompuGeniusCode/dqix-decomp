#include <globaldefs.h>

struct Struct02237e9c { unsigned char pad[0x1b]; signed char field1b; };
extern Struct02237e9c* data_ov031_02290d10;

// USA: func_ov031_02237eb0
ARM int IsGlobal02290d10Set_02237eb0(void) {
	return data_ov031_02290d10 != NULL;
}
