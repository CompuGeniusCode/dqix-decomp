#include <globaldefs.h>

// Reads one bit out of a numbered bit bank. The unused first parameter is the object, so this was
// a member function: callers pass the game work GetScenarioState returns with its bank at +0x8c, with
// indices up to 0x119c, and ov001 passes a 0x1c-stride per-record bank at +3 or +0x10 -- the same
// banks func_ov017_021ce174 writes when it applies a remote command. That these are progress flags
// is read off the hand-written LightingManager.cpp, which switches lighting sets on bit 0x2a at the
// front of the starflight express, and off func_02061c04 pairing each write with a net broadcast.
extern "C" ARM int TestFlagBit(int unused, unsigned char* arr, int index) {
    unsigned char mask;
    if (index < 0) {
        return 0;
    }
    mask = 1 << (index % 8);
    return mask & arr[index / 8];
}
