#include <globaldefs.h>

struct Rgb02070950 {
    int r;
    int g;
    int b;
};

struct EffectParam02070950 {
    unsigned char active;   // 0x0
    unsigned char _pad1;    // 0x1
    unsigned short color;   // 0x2
    unsigned char mode;     // 0x4
    unsigned char _pad5[3]; // 0x5-0x7
    int amount;             // 0x8
    unsigned char _padC[4]; // 0xc-0xf
    int field10;            // 0x10
};

// USA: func_02070950
ARM void SetColoredEffectParam02070950(struct EffectParam02070950* obj, struct Rgb02070950* rgb, int duration, int value, int mode) {
    if (duration < 0) {
        return;
    }
    obj->field10 = duration;
    obj->color = rgb->r | (rgb->g << 5) | (rgb->b << 10);
    obj->amount = (int)(16.667f * (float)value);
    obj->mode = (unsigned char)mode;
    obj->active = 1;
}
