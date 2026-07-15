#include <globaldefs.h>

// USA: func_ov031_02200790
ARM int IsHighNibbleE_02200790(unsigned int v) {
	return (v & 0xf0000000) == 0xe0000000;
}
