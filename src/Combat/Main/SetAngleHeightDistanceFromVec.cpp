#include <globaldefs.h>

extern "C" void func_0202e5d8(void*, int, int, int);

// Passes a packed vector as the angle, height difference and distance that place the point at +0x4
// relative to the anchor at +0x10. func_0202ea4c is the exact inverse -- fix32_Atan2 of the
// flattened difference, the y difference, Vector3fix_Distance -- which fixes the meaning of the
// three fields. The reconstruction takes the horizontal leg as sqrt(distance^2 - height^2), so a
// height larger than the distance feeds a negative value to fix32_Sqrt.
extern "C" ARM void SetAngleHeightDistanceFromVec(void* obj, int* vec) {
    func_0202e5d8(obj, vec[0], vec[1], vec[2]);
}
