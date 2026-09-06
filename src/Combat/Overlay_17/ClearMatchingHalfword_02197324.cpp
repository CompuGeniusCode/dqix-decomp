#include <globaldefs.h>

// USA: func_ov017_02197324
ARM void ClearMatchingHalfword_02197324(unsigned char* obj, unsigned short key) {
	unsigned short* p = (unsigned short*)(obj + 0x44b8);
	for (int i = 0; i < 4; i++, p++) {
		if (*p == key) {
			*p = 0;
			return;
		}
	}
}
