#include <globaldefs.h>

struct Vec3;
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);

// USA: func_0202e9f4
ARM void SubtractVec3Fields0202e9f4(void* obj, struct Vec3* v) {
    SubtractVec3((struct Vec3*)((char*)obj + 0x10), (struct Vec3*)((char*)obj + 0x4), v);
}
