#include <globaldefs.h>

extern "C" void* func_ov000_02161318(void* p0, int p1);

// USA: func_ov000_02162b70
ARM void SetByteField0x43eOnEntry(void* p, int key, unsigned char val) {
	void* entry = func_ov000_02161318((char*)p + 0x3760, key);
	if (entry != 0) {
		*((unsigned char*)entry + 0x43e) = val;
	}
}
