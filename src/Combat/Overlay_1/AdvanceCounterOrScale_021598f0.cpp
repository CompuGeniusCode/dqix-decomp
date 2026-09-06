#include <globaldefs.h>

extern "C" ARM int fix32_Divide(unsigned int numerHi, unsigned int denomLo);

struct Range_021598f0 { char pad0[0x10]; int f10; int f14; };
struct Counter_021598f0 { char pad0[0x68]; int f68; char pad1[0x90 - 0x6c]; int f90; char pad2[0x118 - 0x94]; int f118; };

// USA: func_ov001_021598f0  (semantic: AdvanceCounterOrScale_021598f0)
extern "C" ARM int func_ov001_021598f0(struct Range_021598f0* obj1, struct Counter_021598f0* obj2) {
    int total = obj1->f14;
    int cur = obj2->f68;
    if (cur >= total) {
        obj2->f90 = obj1->f10;
        obj2->f68 = 0;
        return 0;
    }
    if (cur <= 0) {
        int delta = obj1->f10 - obj2->f90;
        if (total == 0) {
            return 0;
        }
        obj2->f118 = fix32_Divide(delta, total << 12);
    } else {
        obj2->f90 += obj2->f118;
    }
    obj2->f68 = obj2->f68 + 1;
    return 1;
}
