#include <globaldefs.h>
#pragma optimize_for_size off

extern "C" void* CallWithZeroExtra_0223e218(void*, void*, void*, int);
void IncrementCounterAndMaybeFire_0223c2d0(void);
extern void* data_ov031_02290d34;

struct Slot0223c278 {
	int field0;
	short field4;
	short field6;
	unsigned char pad8;
	unsigned char field9;
};

// USA: func_ov031_0223c278
ARM int RegisterHandlerSlot_0223c278(int d) {
	Slot0223c278* slot = (Slot0223c278*)data_ov031_02290d34;
	if (slot->field9 != 0) {
		return 0;
	}
	slot->field0 = (int)CallWithZeroExtra_0223e218((void*)1, (void*)IncrementCounterAndMaybeFire_0223c2d0, slot, 0xc8);
	slot->field4 = 0;
	slot->field6 = (short)d;
	slot->field9 = 1;
	return 1;
}
