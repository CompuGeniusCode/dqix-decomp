#include <globaldefs.h>

int GetField9OrZero_022134b0(void);
extern "C" void func_ov031_022132d4(void);
extern "C" void func_ov031_022141d4(unsigned char*);
void UpdateSlotFromEntity_02213450(unsigned char);

// USA: func_ov031_022130ac
ARM int HandleTierSpecialCase_022130ac(void) {
	unsigned char v = (unsigned char)GetField9OrZero_022134b0();
	if (v == 0 || v == 0x12) {
		func_ov031_022132d4();
		return 1;
	}
	func_ov031_022141d4(&v);
	UpdateSlotFromEntity_02213450(v);
	return 0;
}
