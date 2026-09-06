#include <globaldefs.h>

struct StatSrc02214410 {
    unsigned char pad0[0x10];
    int w10;
    unsigned char b14;
    unsigned char b15;
    unsigned char b16;
    unsigned char pad17[0x22 - 0x17];
    unsigned char b22;
};

// USA: func_ov031_02214410
#pragma optimize_for_size off
ARM int GetAdjustedStat_02214410(StatSrc02214410* obj) {
    unsigned char flag = obj->b22;
    if (flag == 0) flag = obj->b15;
    unsigned char catB = obj->b16;
    if (catB < 10) {
        unsigned char kind = obj->b14;
        if (kind == 3) return 0xffff3864 - flag;
        if (kind == 4) {
            return -0xc800 - flag;
        }
        return 0xffff379c - flag;
    }
    if (catB < 0xd) return 0xffff34e0 - flag;
    int v = obj->w10;
    if (v == 0) return 0xffff3cb0 - flag;
    if (v == -1) return 0xffff347c - flag;
    if (v == -2) return 0xffff3418 - flag;
    if (v == -3) return 0xffff33b4 - flag;
    if (v == -4) return 0xffff30f8 - flag;
    if (v == -5) return 0xffff3094 - flag;
    if (v == -6) return 0xffff3030 - flag;
    return v;
}
