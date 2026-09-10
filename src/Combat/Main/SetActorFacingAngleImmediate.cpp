#include <globaldefs.h>

struct FixedVec3 {
    int x;
    int y;
    int z;
};

struct Actor {
    char unknown0[0x50];
    struct FixedVec3 rotation;
    char unknown5c[0x52];
    short targetFacingAngle;
};

extern "C" short _Z22fix32ReduceAngle0To2Pii(int);

// Sets an actor's facing angle with no turn. fix32ReduceAngle0To2Pi wraps the value into
// targetFacingAngle at +0xae and the same value goes into rotation.y at +0x50 -- the pair
// func_02033710 otherwise closes at +0xb0 times GetFrameTimeStep per frame. That function clears
// bit 0x8000 of +0xc4 once the turn finishes and Object3D::IsTransitioningAnimations is false, so
// the flag reads as turn-in-progress. func_020338d4 calls this with the atan2 of the vector to
// some target point; SetActorFacingAngle only routes here for motion states 3 and 4. The rotation
// triple at +0x50 is Object3D::rotation_, so an Object3D sits at +0 of the actor; that class ends
// at 0xac, which puts the facing angle and the flag word past it in the actor's own fields.
extern "C" ARM void SetActorFacingAngleImmediate(struct Actor* actor, int angle) {
    struct FixedVec3* rotationDst = (struct FixedVec3*)((char*)actor + 0x50);
    struct FixedVec3* rotationSrc = (struct FixedVec3*)((char*)actor + 0x50);
    int x, y, z;
    actor->targetFacingAngle = _Z22fix32ReduceAngle0To2Pii(angle);
    z = rotationSrc->z;
    y = actor->targetFacingAngle;
    x = rotationSrc->x;
    rotationDst->x = x;
    rotationDst->y = y;
    rotationDst->z = z;
    *(unsigned short*)((char*)actor + 0xc4) &= ~0x8000;
}
