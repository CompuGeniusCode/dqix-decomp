#include <globaldefs.h>

struct Vec3Target0203a46c {
    char unk[0x1c];
    int x;
    int y;
    int z;
};

// USA: func_0203a46c
ARM void SetVec3At0x1c(struct Vec3Target0203a46c* obj, int x, int y, int z) {
    obj->x = x;
    obj->y = y;
    obj->z = z;
}
