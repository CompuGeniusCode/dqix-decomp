#include <globaldefs.h>

struct ClampTarget_0203fc84 {
    char unk[0x2C];
    unsigned short value;
};

// USA: func_0203fc84
ARM void ClampValueAndStoreAt0x2c(struct ClampTarget_0203fc84* obj, int value) {
    if (value > 0x1F) {
        value = 0x1F;
    } else if (value < 0) {
        value = 0;
    }
    obj->value = value;
}
