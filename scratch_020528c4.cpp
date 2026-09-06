#include <globaldefs.h>

struct Thresholds0210791c {
    float t0;
    float t1;
    float t2;
    char pad0xc[4];
    float cap;
};
extern struct Thresholds0210791c data_0210791c;

#pragma optimize_for_size off

// USA: func_020528c4
ARM int ClassifyValue020528c4(float v) {
    if (v < 0.0f) goto neg1;
    if (data_0210791c.cap < v) {
neg1:
        return -1;
    }
    if (v >= data_0210791c.t0) return 3;
    if (v >= data_0210791c.t1) return 2;
    return v >= data_0210791c.t2 ? 1 : 0;
}
