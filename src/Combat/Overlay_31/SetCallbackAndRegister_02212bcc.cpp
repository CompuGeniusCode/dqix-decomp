#include <globaldefs.h>

struct Ctx02212bcc { unsigned char pad0[4]; void* field4; unsigned char pad1[0x48 - 8]; int field48; };
struct Data0224e5c0_02212bcc { Ctx02212bcc* field0; };
extern Data0224e5c0_02212bcc data_ov031_0224e5c0;
extern "C" void func_ov031_022128b8(void);
int RegisterCallback_0223e8ac(void* arg);

// USA: func_ov031_02212bcc
ARM int SetCallbackAndRegister_02212bcc(void* callback) {
	Ctx02212bcc* p = data_ov031_0224e5c0.field0;
	if (p == NULL) return 0;
	p->field4 = callback;
	if (data_ov031_0224e5c0.field0->field48 == 0) {
		func_ov031_022128b8();
	} else {
		RegisterCallback_0223e8ac((void*)func_ov031_022128b8);
	}
	return 1;
}
