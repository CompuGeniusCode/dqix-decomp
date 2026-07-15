#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" int func_ov003_0216ffbc(void* param);

struct S021700bc { char pad[0x170]; void* field170; };

// USA: func_ov003_021700bc
ARM void InitField170_021700bc(S021700bc* param) {
	param->field170 = (char*)func_02012fe4() + 0x840;
	func_ov003_0216ffbc(param);
}
