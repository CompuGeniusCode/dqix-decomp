#include <globaldefs.h>

extern "C" unsigned char* func_ov017_0219219c(void);

// USA: func_ov017_02191b40
ARM void ClearByteAtPtr_02191b40(void) {
	unsigned char* p = func_ov017_0219219c();
	if (p) {
		*p = 0;
	}
}
