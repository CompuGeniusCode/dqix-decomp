#include <globaldefs.h>
#include "System/Random.h"

extern "C" void* func_ov000_02153710(void*, short);
extern "C" int func_ov000_02159dbc(void*, short);

struct RngHolder_021d9ad8 { struct Random* rng; };

// USA: func_ov024_021d9ad8
ARM int RandomScaleField6cPlus10_021d9ad8(struct RngHolder_021d9ad8* holder, unsigned short category, int unused1, int unused2, int unused3, int fallback) {
    int inRange = 0;
    if (category <= 3) {
        inRange = 1;
    }
    float value;
    if (inRange) {
        char* base = (char*)func_ov000_02153710(holder->rng, (short)category);
        if (base == NULL) {
            return fallback;
        }
        int idx = *(int*)(base + 0x950);
        unsigned short v = *(unsigned short*)(base + idx * 2 + 0x16c);
        value = v;
    } else {
        int v = func_ov000_02159dbc(holder->rng, (short)category);
        value = v;
    }
    float sum = 10.0f + 2.0f * value;
    float randomFactor = NextRandomFloatBetween(holder->rng, -0.1f, 0.1f);
    return (int)(sum + sum * randomFactor);
}
