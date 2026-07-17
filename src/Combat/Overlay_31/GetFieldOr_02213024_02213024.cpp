#include <globaldefs.h>

extern "C" unsigned int GetField9OrZero_022134b0(void);

struct Global0224e5c4b {
	unsigned char pad[0xc];
	void *pField;
};

extern Global0224e5c4b data_ov031_0224e5c4;

// USA: func_ov031_02213024
ARM int GetFieldOr_02213024_02213024(void) {
	unsigned int result = 0xff;
	unsigned int val = GetField9OrZero_022134b0();
	if (val >= 0xa && val <= 0x10) {
		result = *((unsigned char*)data_ov031_0224e5c4.pField + 0x17);
	}
	return result;
}
