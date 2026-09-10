#include <globaldefs.h>
extern "C" int IsCombatantMotionActive(char*);

struct Bytes02033b88;
extern "C" int SetActorMotionState(struct Bytes02033b88* combatant, int motionState);

struct Obj020397cc {
    char unknown0[0xc1];
    unsigned char unknownC1 : 2;
    char unknownC2[0x190];
    unsigned char byte_252;
    unsigned char byte_253;
};

// Stops the combatant and takes movement away from it. The byte at +0x252 is the live
// movement-enable flag: func_02038138, the update that reads the touch point and drives
// SetActorFacingAngle and SetActorMotionStateIfChanged, drops its move flag at 0x0203831c when
// +0x252 is clear and never reaches the steering path. The motion state it resets on the way out
// at 0x02038374 is guarded on +0x252 still being set, so that is not what a clear flag triggers.
// The byte at +0x253 is the saved copy func_02039830 puts back into +0x252; func_02037d10 sets
// both to 1 when the combatant is built.
// The motion is only reset when the caller asks for it, the combatant is still enabled, the byte
// at +0x26c reads 0 and bit 1 of the two-bit field at +0xc1 is clear; what that bit and the +0x26c
// byte mean is not established. Every decompiled call site passes 1 for the flag.
extern "C" ARM void StopCombatantMovement(struct Obj020397cc* combatant, int stopMotion) {
    if (stopMotion && combatant->byte_252 && IsCombatantMotionActive((char*)(combatant)) == 0 && (combatant->unknownC1 & 2) == 0) {
        SetActorMotionState((struct Bytes02033b88*)combatant, 0);
    }
    combatant->byte_253 = 0;
    combatant->byte_252 = 0;
}
