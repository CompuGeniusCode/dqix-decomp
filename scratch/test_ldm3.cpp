#include <globaldefs.h>

struct Vec3i_test { int a, b, c; };

ARM int TestLdm3(int* base) {
    Vec3i_test v = *(Vec3i_test*)((char*)base + 0x10);
    return v.a + v.b + v.c;
}
