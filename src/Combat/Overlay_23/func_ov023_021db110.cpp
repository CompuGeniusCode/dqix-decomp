#include <globaldefs.h>
#include "std_library_functions.h"

unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long dividend, unsigned int divisor, unsigned int flag);
extern "C" int _s32_div_f(int, int);
extern "C" int func_020017a4(int x);

struct Particle021db110 {
    short timer;
    short duration;
    short paramA;
    short paramB;
};

struct Obj021db110 {
    struct Particle021db110 particles[3];
    unsigned long long lastTick;
    short frameCounter;
    short retrigger;
    unsigned char active;
};

// USA: func_ov023_021db110  (semantic: UpdateSparkleParticles_021db110)
extern "C" ARM void func_ov023_021db110(struct Obj021db110* obj) {
    if (obj->active == 0) return;

    unsigned long long scaledNow = _ll_udiv(GetCurrentTimestamp() << 6, 0x82ea, 0);
    if (scaledNow - obj->lastTick > 30) {
        obj->lastTick = scaledNow;
    } else {
        return;
    }

    int i;
    for (i = 0; i < 3; i++) {
        obj->particles[i].timer--;
        if (obj->particles[i].timer <= 0) obj->particles[i].timer = 0;
    }

    obj->retrigger--;
    if (obj->retrigger <= 0) {
        obj->retrigger = 0;
        for (int j = 0; j < 3; j++) {
            struct Particle021db110* p = &obj->particles[j];
            if (p->timer > 0) continue;
            if (rand() % 5 != 0) continue;

            p->timer = p->duration;
            p->paramA = (short)(rand() % 50);
            p->paramB = (short)(rand() % 15);

            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                if (obj->particles[k].timer <= 0) continue;
                if (func_020017a4(p->paramA - obj->particles[k].paramA) > 12) continue;
                if (func_020017a4(p->paramB - obj->particles[k].paramB) <= 12) {
                    p->timer = 0;
                    break;
                }
            }
            obj->retrigger = 2;
            break;
        }
    }

    obj->frameCounter++;
    if (obj->frameCounter >= 0x28) obj->frameCounter = 0;
}
