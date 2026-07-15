#include <globaldefs.h>

#pragma optimize_for_size off
// USA: func_ov017_0218f57c
ARM void SetLowNibble56b_0218f57c(void* obj, int val) {
	void* inner = *(void**)((char*)obj + 0x150);
	if (!inner) return;
	unsigned char* p = (unsigned char*)inner + 0x56b;
	*p = (*p & ~0xf) | ((unsigned char)val & 0xf);
}
