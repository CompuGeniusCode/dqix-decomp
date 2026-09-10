#include <globaldefs.h>

// Word 0 of the multiplayer state object is the session state, and 0 means no session; the curated
// IsHostOrSinglePlayer and IsMultiplayerLocalSlotNonZero test the same word the same way. The object
// is the one GetMultiplayerState (0x0202ae18) hands out, and 170 of this function's 171 distinct
// callers fetch it from there. Neighbouring functions drive that word to 2, 3, 5 and 6 as a session
// comes up; func_0202b900 searches the peer array at +0x10, 0xc0 bytes per entry with a six-byte
// identifier at +4, presumably the MAC address, and sets the word to 6 once it matches one.
extern "C" ARM int IsMultiplayerActive(int* obj) {
    return obj[0] != 0;
}
