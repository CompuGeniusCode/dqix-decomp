#include <globaldefs.h>

// USA: func_ov031_0220868c
ARM int LengthUntilDotOrEnd_0220868c(const char* str) {
	const char* orig = str;
	while (*str != '.' && *str != 0) str++;
	return str - orig;
}
