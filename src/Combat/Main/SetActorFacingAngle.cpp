#include <globaldefs.h>

struct Obj02033874;

struct Obj02033834 {
    char pad0[0xae];
    short fae;           // 0xae
    char pad1[0x0e];     // 0xb0..0xbd
    unsigned char mode;  // 0xbe
    char pad2[0x05];     // 0xbf..0xc3
    unsigned short fc4;  // 0xc4
};

extern "C" short _Z22fix32ReduceAngle0To2Pii(int);
extern "C" void SetActorFacingAngleImmediate(struct Obj02033874* obj, int arg);

// Sets an actor's target facing angle. fix32ReduceAngle0To2Pi wraps the value into the s16 at
// +0xae; func_02033920 hands the same object to Object3D::MaybeSetRegularAnimation and compares
// +0xae against the applied rotation y at +0x54 with fix32SignedAngleDistance. func_020338b0
// derives the value through func_02032424 (subtract, normalize, fix32_Atan2) over two world
// positions, so it is a yaw. Mode byte +0xbe of 3 or 4 takes the snap path through the
// immediate-apply sibling 0x02033874; clearing 0x8000 at +0xc4 drops the turn animation.
extern "C" ARM void SetActorFacingAngle(struct Obj02033834* obj, int arg) {
    if (obj->mode == 4 || obj->mode == 3) {
        SetActorFacingAngleImmediate((struct Obj02033874*)obj, arg);
    } else {
        obj->fae = _Z22fix32ReduceAngle0To2Pii(arg);
    }
    obj->fc4 &= ~0x8000;
}
