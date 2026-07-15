#include <globaldefs.h>

struct S021a7a5c { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021a79f0(S021a7a5c*);

// USA: func_ov017_021a7a5c
ARM void CallHelperAndSetFlag_021a7a5c(S021a7a5c* obj) {
	func_ov017_021a79f0(obj);
	obj->f1 = 1;
}
