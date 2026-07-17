#include <globaldefs.h>

int GetField9OrZero_022134b0(void);
void* GetFieldPtrByMask_022133f8(unsigned int mask);
extern "C" int func_ov031_02213ce0(void*);
extern "C" int func_ov031_02213dd8(void*);

// USA: func_ov031_02213c9c
ARM int RunFieldHandlerByCase_02213c9c(void) {
	int c = GetField9OrZero_022134b0();
	void* p = GetFieldPtrByMask_022133f8(0x10);
	if (c == 7) {
		c = func_ov031_02213ce0(p);
	} else if (c == 8) {
		c = func_ov031_02213dd8(p);
	}
	return c;
}
