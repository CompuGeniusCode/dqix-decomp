#include <globaldefs.h>

struct A02159820 { char pad[0x10]; int f10; int f14; };
struct B02159820 { char pad0[0x64]; int f64; char pad1[0x24]; float f8c; char pad2[0x84]; float f114; };

// USA: func_ov001_02159820  (semantic: UpdateProgressValue_02159820)
extern "C" ARM int func_ov001_02159820(A02159820* a, B02159820* b) {
    int limit = a->f14;
    int counter = b->f64;
    if (counter >= limit) {
        b->f8c = (float)a->f10;
        b->f64 = 0;
        return 0;
    }
    float bc = b->f8c;
    if (counter <= 0) {
        int diff = a->f10 - (int)bc;
        if (limit == 0) return 0;
        b->f114 = (float)diff / (float)limit;
    } else {
        b->f8c = bc + b->f114;
    }
    b->f64 = b->f64 + 1;
    return 1;
}
