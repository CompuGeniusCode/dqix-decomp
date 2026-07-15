#include <globaldefs.h>

struct S021a9314 { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021a92a0(S021a9314*);

// USA: func_ov017_021a9314
ARM void CallHelperAndSetFlag_021a9314(S021a9314* obj) {
	func_ov017_021a92a0(obj);
	obj->f1 = 1;
}
