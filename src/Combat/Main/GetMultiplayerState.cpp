#include <globaldefs.h>

extern int data_020fefec;

// Returns the global local-play state at 0x020fefec, built by the static initialiser
// __sinit_020e5b28: the console owner's identity plus a ten-slot peer table. The constructor
// func_0202aec0 copies the owner's nickname out of the DS user settings mirror at 0x027ffc80, and
// func_0202baf4 keys the slots at +0x10 on a six-byte address, not established to be a
// MAC, with a 0xfa0-tick expiry. func_0202b900 matches that key and stamps a battle timestamp on
// the record, which seems to be joining that peer's game; 48 of the 443 references only test +0x0.
extern "C" ARM void* GetMultiplayerState(void) {
    return &data_020fefec;
}
