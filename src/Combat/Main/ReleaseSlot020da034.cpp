#include <globaldefs.h>

extern int GetData02104304Field4();
extern "C" void func_020301c8(int, int);

struct SlotManager020da034 {
    unsigned char pad[8];
    unsigned short usedMask;
    unsigned char pad2[2];
    int slots[1];
};

// USA: func_020da034
ARM void ReleaseSlot020da034(SlotManager020da034* mgr, int index) {
    func_020301c8(GetData02104304Field4(), mgr->slots[index]);
    mgr->slots[index] = -1;
    mgr->usedMask &= ~(1 << index);
}
