#include <globaldefs.h>

// USA: func_ov031_0221170c
ARM unsigned long long GetFields04AsPacked64_0221170c(unsigned int* p) {
	return ((unsigned long long)p[0] << 32) | (unsigned long long)p[1];
}
