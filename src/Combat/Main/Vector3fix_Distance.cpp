#include <globaldefs.h>

struct Vec3s32 { int x; int y; int z; };

#define REG_SQRTCNT      (*(volatile unsigned short*)0x040002b0)
#define REG_SQRT_RESULT  (*(volatile unsigned int*)0x040002b4)
#define REG_SQRTPARAM_LO (*(volatile unsigned int*)0x040002b8)
#define REG_SQRTPARAM_HI (*(volatile unsigned int*)0x040002bc)

// USA: func_020c3030
// Distance between two points, through the hardware square root at 0x040002b0. The squared sum goes
// in shifted up two and the result comes back doubled, so (result + 1) >> 1 is the square root of
// the sum rounded to nearest rather than truncated; the spin on bit 15 of SQRTCNT waits for the
// unit to finish.
extern "C" ARM int Vector3fix_Distance(Vec3s32* pointA, Vec3s32* pointB) {
    int dx = pointA->x - pointB->x;
    long long sq = (long long)dx * dx;
    int dy = pointA->y - pointB->y;
    sq += (long long)dy * dy;
    int dz = pointA->z - pointB->z;
    sq += (long long)dz * dz;
    REG_SQRTCNT = 1;
    unsigned long long scaled = (unsigned long long)sq << 2;
    REG_SQRTPARAM_LO = (unsigned int)scaled;
    REG_SQRTPARAM_HI = (unsigned int)(scaled >> 32);
    while (REG_SQRTCNT & 0x8000) {}
    return (int)(REG_SQRT_RESULT + 1) >> 1;
}
