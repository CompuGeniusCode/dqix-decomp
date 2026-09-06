#include <globaldefs.h>

struct Vec3Block_test { unsigned int v[3]; };
struct Vec4Block_test { struct Vec3Block_test xyz; unsigned int pad; };

ARM void TestWriteback(struct Vec4Block_test* src, struct Vec3Block_test* dst) {
    for (int i = 0; i < 4; i++) {
        *dst = src->xyz;
        src++;
        dst++;
    }
}
