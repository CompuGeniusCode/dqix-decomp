#include <globaldefs.h>

extern "C" int func_020b6d10(void* v, int* outA, int* outB);

struct Vec3copy0202ec84 {
    unsigned int v[3];
};

// USA: func_0202ec84
ARM int ComputeTwoFromVec3_0202ec84(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2) {
    struct Vec3copy0202ec84 local = *src;
    int a, b;
    int result = func_020b6d10(&local, &a, &b);
    *out1 = a;
    *out2 = b;
    return result;
}
