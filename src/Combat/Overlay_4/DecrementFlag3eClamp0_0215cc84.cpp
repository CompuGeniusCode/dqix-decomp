#include <globaldefs.h>

struct Struct021707d8_0215cc84 { char pad[0x8]; unsigned char* ptr; };
extern Struct021707d8_0215cc84 data_ov004_021707d8;
extern "C" void func_ov004_021578a8(void* obj);

// USA: func_ov004_0215cc84  (semantic: DecrementFlag3eClamp0_0215cc84)
extern "C" ARM int func_ov004_0215cc84(void* obj) {
	if (data_ov004_021707d8.ptr[0x3e] != 0) {
		data_ov004_021707d8.ptr[0x3e]--;
	}
	func_ov004_021578a8(obj);
	return 0;
}
