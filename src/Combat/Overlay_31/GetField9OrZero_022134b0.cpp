#include <globaldefs.h>

struct Struct022134b0
{
	unsigned char pad[9];
	unsigned char field9;
};

struct Global0224e5c4
{
	unsigned char pad[0xc];
	Struct022134b0* pField;
};

extern Global0224e5c4 data_ov031_0224e5c4;

// USA: func_ov031_022134b0
ARM int GetField9OrZero_022134b0(void) {
	Struct022134b0* p = data_ov031_0224e5c4.pField;
	if (p != NULL) {
		return p->field9;
	}
	return 0;
}
