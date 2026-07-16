#include <globaldefs.h>

extern "C" void func_ov027_021d8c6c(void* obj, int type, void* val);

// USA: func_ov027_021d9e04
void SetShortField13_021d9e04(void* obj, short val) {
	short local = val;
	func_ov027_021d8c6c(obj, 13, &local);
}
