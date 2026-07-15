#include <globaldefs.h>

int GetGlobalField0x1c020421a0();

struct S02160b2c { char pad[0x464]; unsigned int flags464; };

// USA: func_ov003_02160b2c
ARM void ClearGlobalField9ae_02160b2c(S02160b2c* obj) {
	if (!(obj->flags464 & 0x20000)) {
		*(unsigned char*)(GetGlobalField0x1c020421a0() + 0x1000 + 0x9ae) = 0;
	}
}
