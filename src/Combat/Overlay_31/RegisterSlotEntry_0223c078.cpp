#include <globaldefs.h>
#pragma optimize_for_size off

void StoreSignedPairWithFlag020c5100(unsigned short* dst, int flag, int value);
extern "C" void* CallWithZeroExtra_0223e218(void*, void*, void*, int);
void UpdateCounterAndReportSigned_0223c150(void);

struct Bytes022493a0 { unsigned char pad[8]; unsigned char b8, b9, ba, bb; };
extern struct Bytes022493a0 data_ov031_022493a0;
extern void* data_ov031_02290d34;

struct Slot0223c078 {
	int field0;
	short field4;
	short field6;
	unsigned char field8;
	unsigned char field9;
};

// USA: func_ov031_0223c078
ARM int RegisterSlotEntry_0223c078(int idx, int mode, int c, int d) {
	signed char local[4];
	local[0] = data_ov031_022493a0.b8;
	local[1] = data_ov031_022493a0.b9;
	local[2] = data_ov031_022493a0.ba;
	local[3] = data_ov031_022493a0.bb;

	Slot0223c078* slot;
	if (mode == 1) {
		slot = (Slot0223c078*)data_ov031_02290d34;
	} else {
		slot = (Slot0223c078*)((char*)data_ov031_02290d34 + 0xc);
	}

	if (slot->field9 != 0) {
		return 0;
	}

	if (mode == 1) {
		StoreSignedPairWithFlag020c5100((unsigned short*)0x4001050, c, local[idx]);
	} else {
		StoreSignedPairWithFlag020c5100((unsigned short*)0x4000050, c, local[idx]);
	}

	slot->field0 = (int)CallWithZeroExtra_0223e218((void*)1, (void*)UpdateCounterAndReportSigned_0223c150, slot, 0xc8);
	slot->field4 = 0;
	slot->field8 = (unsigned char)idx;
	slot->field6 = (short)d;
	slot->field9 = 1;
	return 1;
}
