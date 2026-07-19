#include <globaldefs.h>

struct EntityStruct02224a20 { unsigned char pad[0x11f]; signed char field11f; };
extern EntityStruct02224a20* data_ov031_02250bfc;
extern "C" void func_ov031_02224fa4(int a, int b);

// USA: func_ov031_02224a20  (semantic: SetField11fPair_02224a20)
extern "C" ARM void func_ov031_02224a20(int arg) {
	if (arg == data_ov031_02250bfc->field11f) {
		return;
	}
	func_ov031_02224fa4(arg, 1);
	func_ov031_02224fa4(data_ov031_02250bfc->field11f, 0);
	data_ov031_02250bfc->field11f = (signed char)arg;
}
