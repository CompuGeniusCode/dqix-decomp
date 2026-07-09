#include <globaldefs.h>

struct SlotArray0203dd10 {
    unsigned char pad[0xc];
    int slots[0x20];
};

// USA: func_0203dd10
ARM void SetSlotIfIndexBelow32(SlotArray0203dd10* obj, unsigned int index, int value) {
    if (index < 0x20) obj->slots[index] = value;
}
