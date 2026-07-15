#include <globaldefs.h>

struct Struct021707d8_0215cd88 { char pad[0x8]; char* ptr; };
extern Struct021707d8_0215cd88 data_ov004_021707d8;
extern "C" void func_ov004_021578a8(void* obj);

// USA: func_ov004_0215cd88
ARM int SetFieldFlagValue6_0215cd88(void* obj) {
	data_ov004_021707d8.ptr[0x3e] = 6;
	func_ov004_021578a8(obj);
	return 0;
}
