#include <globaldefs.h>

extern "C" void* func_ov017_0219c6f4(void*);

// USA: func_ov017_0219cd98
ARM void CallField36bcSetByte2_0219cd98(void* obj) {
	void* p = *(void**)((char*)obj + 0x36bc);
	if (!p) return;
	void* r = func_ov017_0219c6f4(p);
	if (r) *((unsigned char*)r + 0x2) = 1;
}
