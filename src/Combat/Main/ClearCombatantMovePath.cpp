#include <globaldefs.h>
#include "std_library_functions.h"

// Clears a combatant actor's queued movement points: the 16-entry ring of 8-byte {x, z} records at
// +0x1d0, the write cursor at +0x1cb, the read cursor at +0x1cc and the active flag at +0x1cd.
// func_020391ac scales either cursor by 8 to index the ring, wraps both mod 16, pushes an entry from
// Vector3fix_Distance between this actor and another object, and pops one into a VecFx32 with y
// zeroed that Vector3fix_Subtract/Length/Normalize turn into a direction for SetActorMotionState.
// Whether the points are a party-follow trail or a general move queue is not established.
extern "C" ARM void ClearCombatantMovePath(unsigned char* obj) {
    obj[0x1cb] = 0;
    obj[0x1cc] = 0;
    obj[0x1cd] = 0;
    memset(obj + 0x1d0, 0, 0x80);
}
