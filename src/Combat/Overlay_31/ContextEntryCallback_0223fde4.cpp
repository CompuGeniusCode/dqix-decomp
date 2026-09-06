#include <globaldefs.h>

struct Data0223fde4 {
	int field0;
	unsigned char pad[8];
	int (*fieldC)(int);
	unsigned char pad2[8];
	int field18;
};

extern "C" void func_ov031_02240f74(void);
extern "C" void func_ov031_0224030c(void);
void SetFlagForwardAndAwait_022403b0(void);
extern struct Data0223fde4 data_ov031_02290fbc;

// USA: func_ov031_0223fde4  (semantic: ContextEntryCallback_0223fde4)
extern "C" ARM void func_ov031_0223fde4(void (*callback)(void)) {
	func_ov031_02240f74();
	SetFlagForwardAndAwait_022403b0();
	data_ov031_02290fbc.fieldC(data_ov031_02290fbc.field18);
	func_ov031_0224030c();
	data_ov031_02290fbc.field0 = 0;
	callback();
}
