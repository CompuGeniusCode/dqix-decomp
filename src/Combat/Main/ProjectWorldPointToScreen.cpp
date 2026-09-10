#include <globaldefs.h>

extern "C" int _Z31ConvertWorldToScreenCoordinatesPK8Vector3iPiS2_(void* v, int* outA, int* outB);

struct Vec3copy0202ec84 {
    unsigned int v[3];
};

// Copies the world point into a local and forwards it to ConvertWorldToScreenCoordinates, whose
// result, 0 for on screen and -1 for off, is passed straight back. The first argument is never
// read, but all 20 callers fetch GetActiveCamera as well, so it is presumably the camera object and
// this a member function on it; LightingManager::MaybeComputeHorizonPosition passes the camera
// block from BattleStruct+0x3b0 and treats the two outputs as pixel coordinates. Why the vector is
// copied rather than passed through is not established.
extern "C" ARM int ProjectWorldPointToScreen(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2) {
    struct Vec3copy0202ec84 local = *src;
    int a, b;
    int result = _Z31ConvertWorldToScreenCoordinatesPK8Vector3iPiS2_(&local, &a, &b);
    *out1 = a;
    *out2 = b;
    return result;
}
