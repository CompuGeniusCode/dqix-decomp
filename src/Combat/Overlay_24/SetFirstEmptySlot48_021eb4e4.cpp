#include <globaldefs.h>

struct SlotArrayStruct_021eb4e4 {
	char pad[0x48];
	int slots[8];
};

// USA: func_ov024_021eb4e4
ARM void SetFirstEmptySlot48_021eb4e4(struct SlotArrayStruct_021eb4e4* obj, int val) {
	for (int i = 0; i < 8; i++) {
		if (obj->slots[i] == 0) {
			obj->slots[i] = val;
			return;
		}
	}
}
