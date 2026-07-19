#include <globaldefs.h>

extern "C" void func_ov017_021a3ddc(int obj, void* field0);

// USA: func_ov017_021a3dcc
ARM void ForwardObjAndField0_021a3dcc(int obj) {
	func_ov017_021a3ddc(obj, *(void**)obj);
}
