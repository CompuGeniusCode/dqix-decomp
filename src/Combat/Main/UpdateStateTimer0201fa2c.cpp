#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long dividend, unsigned int divisor, unsigned int flag);

struct StateObj0201fa2c {
    unsigned char state;
    unsigned char f1;
    unsigned char f2;
    unsigned char pad3;
    unsigned short f4;
    unsigned short pad6;
    unsigned long long f8;
    float f10;
};

// USA: func_0201fa2c
ARM void UpdateStateTimer0201fa2c(StateObj0201fa2c* obj, unsigned int arg) {
    if (obj->state == 1) {
        if (obj->f1 == 3) {
            obj->state = 3;
            obj->f1 = 0;
            return;
        } else {
            obj->f10 = 176.0f;
            obj->f1 = 0;
            return;
        }
    }
    if (obj->state == 2) {
        if (obj->f2 != 0) return;
        if (obj->f4 != 0) {
            unsigned long long diff = GetCurrentTimestamp() - obj->f8;
            unsigned long long quotient = _ll_udiv(diff << 6, 0x82ea, 0);
            if (quotient >= obj->f4) obj->f1 = 4;
        }
        if (obj->f1 == 4) {
            obj->state = 4;
            obj->f1 = 4;
            obj->f4 = 0;
        }
        obj->f10 = 136.0f;
        return;
    }
    if (obj->state == 3) {
        obj->f10 = obj->f10 - 6.0f * ((float)arg / 33.333332f);
        if (obj->f10 < 136.0f) {
            obj->f10 = 136.0f;
            obj->state = 2;
        }
        return;
    }
    if (obj->state != 4) return;
    obj->f10 = obj->f10 + 6.0f * ((float)arg / 33.333332f);
    if (176.0f < obj->f10) {
        obj->f10 = 176.0f;
        obj->state = 1;
    }
}
