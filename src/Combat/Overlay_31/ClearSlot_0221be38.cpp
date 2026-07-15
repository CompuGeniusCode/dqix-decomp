#include <globaldefs.h>

extern "C" void func_020ca390(int, void*, unsigned int);

struct Slot_0221be38 { unsigned char data[0x100]; };

// USA: func_ov031_0221be38
ARM void ClearSlot_0221be38(Slot_0221be38 *slots, int idx) {
	func_020ca390(0, &slots[idx], 0x100);
	slots[idx].data[0xe7] = 0xff;
}
