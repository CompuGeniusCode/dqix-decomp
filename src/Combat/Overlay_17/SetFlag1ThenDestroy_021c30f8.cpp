#include <globaldefs.h>

struct Obj1_021c30f8 { unsigned char b0; unsigned char b1; };
extern "C" void func_ov017_021c310c(Obj1_021c30f8* obj);

// USA: func_ov017_021c30f8
ARM void SetFlag1ThenDestroy_021c30f8(Obj1_021c30f8* obj) {
	obj->b1 = 1;
	func_ov017_021c310c(obj);
}
