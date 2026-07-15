#include <globaldefs.h>

// USA: func_ov017_02195550
ARM int CheckThreeFlags_02195550(unsigned char* obj) {
	obj += 0x4000;
	if (obj[0x31e]) {
		return 1;
	}
	unsigned char* p = *(unsigned char**)(obj + 0x41c);
	if (*p) {
		return 1;
	}
	return obj[0x2f0] != 0;
}
