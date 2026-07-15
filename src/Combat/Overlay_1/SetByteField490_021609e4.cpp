#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* p);
extern "C" void* func_0205ec34(void);

// USA: func_ov001_021609e4
ARM int SetByteField490_021609e4(void* p) {
	int v = func_ov017_021d60f4(p);
	*((unsigned char*)func_0205ec34() + 0x490) = (unsigned char)v;
	return 1;
}
