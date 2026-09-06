#include <globaldefs.h>

struct Q02211db0 {
	int field0;
	unsigned short field4;
	char pad[0xc - 0x6];
	unsigned char field0xc;
};

struct Struct0224e5b4_02211db0 {
	char pad4[4];
	Q02211db0* field4;
};

extern Struct0224e5b4_02211db0 data_ov031_0224e5b4;
extern "C" void func_ov031_02211f24(void);

// USA: func_ov031_02211db0  (semantic: SetField4ThenCheckByteC_02211db0)
extern "C" ARM int func_ov031_02211db0(void) {
	Q02211db0* q = data_ov031_0224e5b4.field4;
	if (q == NULL) return 0;
	if (q->field0 != 0) {
		q->field4 = 3;
		func_ov031_02211f24();
		q = data_ov031_0224e5b4.field4;
		return q->field0xc != 0;
	} else {
		return 0;
	}
}
