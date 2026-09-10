#include <globaldefs.h>

struct Actor;

struct Actor {
    char unknown0[0xae];
    short targetFacingAngle;           // 0xae
    char unknownb0[0x0e];     // 0xb0..0xbd
    unsigned char mode;  // 0xbe
    char unknownbf[0x05];     // 0xbf..0xc3
    unsigned short stateFlags;  // 0xc4
};

extern "C" short _Z22fix32ReduceAngle0To2Pii(int);
extern "C" void SetActorFacingAngleImmediate(struct Actor* actor, int angle);

// Sets an actor's target facing angle. fix32ReduceAngle0To2Pi wraps the value into the signed
// halfword at +0xae; func_02033920 hands the same object to Object3D::MaybeSetRegularAnimation and
// compares +0xae against the applied rotation y at +0x54 with fix32SignedAngleDistance. func_020338b0
// derives the value through func_02032424 (subtract, normalize, fix32_Atan2) over two world
// positions, so it is a yaw. Mode byte +0xbe of 3 or 4 takes the snap path through the
// immediate-apply sibling 0x02033874; clearing 0x8000 at +0xc4 drops the turn animation.
// The record begins with an Object3D -- position_ at +0x44 and rotation_ at +0x50 line up with the
// class layout, and the turn is what closes rotation_.y onto +0xae -- so everything from +0xae on
// is the actor's own. Only bit 0x8000 of the halfword at +0xc4 has a reader here; func_02033920
// sets it once MaybeSetRegularAnimation accepts the turn animation.
extern "C" ARM void SetActorFacingAngle(struct Actor* actor, int angle) {
    if (actor->mode == 4 || actor->mode == 3) {
        SetActorFacingAngleImmediate((struct Actor*)actor, angle);
    } else {
        actor->targetFacingAngle = _Z22fix32ReduceAngle0To2Pii(angle);
    }
    actor->stateFlags &= ~0x8000;
}
