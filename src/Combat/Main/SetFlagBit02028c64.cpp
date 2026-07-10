#include <globaldefs.h>

void InsertShortIntoTable021098f4(unsigned short);

struct Obj02028c64 {
    char pad[4];
    unsigned short flags;   // 0x4
};

// USA: func_02028c64
ARM void SetFlagBit02028c64(struct Obj02028c64* obj, int index) {
    if (index < 0x10) {
        obj->flags |= 1 << index;
        return;
    }
    InsertShortIntoTable021098f4(5);
}
