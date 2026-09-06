#include <globaldefs.h>

// USA: func_ov006_021585ac
ARM void SetFlags_021585ac_021585ac(void* p) {
	unsigned char* q = (unsigned char*)p;
	if (q[0x434] == 0) {
		q[0x434] = 1;
		q[0x433] = 1;
	}
}
