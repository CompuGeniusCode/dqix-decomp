#include <globaldefs.h>

// USA: func_ov017_0219735c
ARM int HasMatchingHalfword_0219735c(unsigned char* obj, unsigned short key) {
	unsigned short* p = (unsigned short*)(obj + 0x44b8);
	for (int i = 0; i < 4; i++, p++) {
		if (*p == key) {
			return 1;
		}
	}
	return 0;
}
