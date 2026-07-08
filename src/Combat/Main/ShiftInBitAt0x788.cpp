#include <globaldefs.h>

struct BitStreamStruct {
    char unk0[0x124];
    int flag;
    char unk128[0x788 - 0x128];
    volatile int bits;
};

// USA: func_0202f984
ARM void ShiftInBitAt0x788(struct BitStreamStruct* obj) {
    if (obj->flag == 0 && obj->bits == 0) {
        return;
    }
    obj->bits <<= 1;
    obj->bits |= 1;
}
