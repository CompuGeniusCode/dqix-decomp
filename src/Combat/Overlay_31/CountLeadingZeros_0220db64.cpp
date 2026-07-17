#include <globaldefs.h>

// USA: func_ov031_0220db64
ARM unsigned int CountLeadingZeros_0220db64(unsigned int value) {
	asm {
		clz value, value
	}
	return value;
}
