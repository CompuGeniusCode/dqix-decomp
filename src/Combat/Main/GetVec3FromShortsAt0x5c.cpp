#include <globaldefs.h>

struct Vec3i_020374f0 {
    int x;
    int y;
    int z;
};

// USA: func_020374f0
ARM struct Vec3i_020374f0 GetVec3FromShortsAt0x5c(unsigned char* src) {
    struct Vec3i_020374f0 v;
    v.x = *(short*)(src + 0x5c);
    v.y = *(short*)(src + 0x5e);
    v.z = *(short*)(src + 0x60);
    return v;
}
