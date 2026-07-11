#include <globaldefs.h>

struct Rgb02070900 {
    int r;
    int g;
    int b;
};

struct EffectParam02070900 {
    unsigned char active;   // 0x0
    unsigned char _pad1;    // 0x1
    unsigned short color;   // 0x2
    unsigned char mode;     // 0x4
    unsigned char _pad5[3]; // 0x5-0x7
    int amount;             // 0x8
};

// USA: func_02070900
ARM void SetColoredEffectParam02070900(struct EffectParam02070900* obj, struct Rgb02070900* rgb, unsigned int value) {
    obj->color = rgb->r | (rgb->g << 5) | (rgb->b << 10);
    obj->amount = (int)(16.667f * (float)value);
    obj->mode = 0x1f;
    obj->active = 1;
}
