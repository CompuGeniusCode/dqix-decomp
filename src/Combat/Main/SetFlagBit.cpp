#include <globaldefs.h>

// Writes one bit of a numbered bit bank, clearing it rather than setting it when the value is zero.
// TestFlagBit at 0x0206dfb0, the next function along, is the matching read and takes the same unused
// first parameter, so both were members of the object the callers pass. Every decompiled caller
// passes the bank at +0x8c of the state GetScenarioState returns, which the hand-written
// LightingManager.cpp reads with TestFlagBit to choose a lighting set, so these are progress flags.
// func_02061c04 pairs each write here with what looks like a net broadcast, but it is not decompiled.
extern "C" ARM void SetFlagBit(void* unused, unsigned char* array, int bit, int value) {
    int i = bit / 8;
    unsigned char mask = 1 << (bit % 8);
    unsigned int v = array[i];
    if (value != 0) {
        v |= mask;
    } else {
        v &= ~mask;
    }
    array[i] = v;
}
