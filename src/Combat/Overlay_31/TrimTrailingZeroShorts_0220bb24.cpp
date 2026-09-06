#include <globaldefs.h>

// USA: func_ov031_0220bb24
ARM int TrimTrailingZeroShorts_0220bb24(unsigned short* arr, int len) {
	while (len != 0 && *(unsigned short*)((char*)(arr + len) - 2) == 0) {
		len--;
	}
	return len;
}
