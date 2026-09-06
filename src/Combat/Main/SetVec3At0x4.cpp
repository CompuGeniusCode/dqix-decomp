#include <globaldefs.h>

struct Vec3Target0202e5c0 {
    char pad[4];
    int x;
    int y;
    int z;
};

// USA: func_0202e5c0
ARM void SetVec3At0x4(struct Vec3Target0202e5c0* obj, int x, int y, int z) {
    obj->x = x;
    obj->y = y;
    obj->z = z;
}
