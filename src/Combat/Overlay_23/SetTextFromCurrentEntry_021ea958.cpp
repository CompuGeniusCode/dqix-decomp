#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" void func_ov017_021d6134(void*, unsigned short);

// USA: func_ov023_021ea958
ARM int SetTextFromCurrentEntry_021ea958(void* obj) {
	void* p = func_02012fe4();
	unsigned short v = *(unsigned short*)p;
	func_ov017_021d6134(obj, v);
	return 1;
}
