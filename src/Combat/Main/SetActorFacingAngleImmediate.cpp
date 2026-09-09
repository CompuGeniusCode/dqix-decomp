#include <globaldefs.h>

struct Vec3_02033874 {
    int x;
    int y;
    int z;
};

struct Obj02033874 {
    char pad[0x50];
    struct Vec3_02033874 vec;
    char pad2[0x52];
    short fae;
};

extern "C" short _Z22fix32ReduceAngle0To2Pii(int);

// Sets an actor's facing angle with no turn. fix32ReduceAngle0To2Pi wraps the value into the target
// angle at +0xae and the same value goes into rotation_.y at +0x50 -- the pair func_02033710 otherwise
// closes at +0xb0 times GetFrameTimeStep per frame. That function clears bit 0x8000 of +0xc4 once
// the turn finishes and Object3D::IsTransitioningAnimations is false, so the flag reads as
// turn-in-progress. func_020338d4 calls this with the atan2 of the vector to a target point;
// SetActorFacingAngle only routes here for motion states 3 and 4.
extern "C" ARM void SetActorFacingAngleImmediate(struct Obj02033874* obj, int arg) {
    struct Vec3_02033874* dst = (struct Vec3_02033874*)((char*)obj + 0x50);
    struct Vec3_02033874* src = (struct Vec3_02033874*)((char*)obj + 0x50);
    int x, y, z;
    obj->fae = _Z22fix32ReduceAngle0To2Pii(arg);
    z = src->z;
    y = obj->fae;
    x = src->x;
    dst->x = x;
    dst->y = y;
    dst->z = z;
    *(unsigned short*)((char*)obj + 0xc4) &= ~0x8000;
}
