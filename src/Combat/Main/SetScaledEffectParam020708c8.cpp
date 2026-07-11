#include <globaldefs.h>

struct EffectParam020708c8 {
    unsigned char active;   // 0x0
    unsigned char _pad1;    // 0x1
    unsigned short color;   // 0x2
    unsigned char mode;     // 0x4
    unsigned char _pad5[3]; // 0x5-0x7
    int amount;             // 0x8
};

// USA: func_020708c8
ARM void SetScaledEffectParam020708c8(struct EffectParam020708c8* obj, unsigned int value) {
    obj->amount = (int)(16.667f * (float)value);
    obj->mode = 1;
    obj->active = 1;
}
