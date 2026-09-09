#include <globaldefs.h>

// Non-zero while the actor has a motion running out of the sub-block at +0x26c that func_02038508
// sets up -- five fix32 vectors, a speed-looking 0x64 at +0x54. ov017's shadow pass consults that
// block only when this byte is set, taking y from block+0x4c on modes 2 and 6 and the shadow value
// from block+0x50 on modes 1 and 4. Callers gate acting on the byte being zero, though
// func_0208aa28 tests it on GetPlayerCombatant, not on the combatant it was asked about.
// That the motion is scripted rather than ordinary walking is inferred from those uses, not proven.
extern "C" ARM unsigned char IsCombatantMotionActive(char* obj) {
    return obj[0x26c];
}
