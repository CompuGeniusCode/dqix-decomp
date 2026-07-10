#include <globaldefs.h>

// USA: func_02030cd8
ARM int WrapAngleDelta(int a, int b) {
    int d = 0;
    if (a < b) {
        d = b - a;
        if (d > 0x3244) d -= 0x6488;
    } else if (b < a) {
        int t = a - b;
        d = -t;
        if (d < -0x3244) d += 0x6488;
    }
    return d;
}
