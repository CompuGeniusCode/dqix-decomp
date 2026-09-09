#include <globaldefs.h>

// True when any of the masked bits are set in the pad state, normally data_02114e30: this frame's
// input in the first halfword and last frame's in the second, which is what makes IsKeyTriggered
// "newly pressed" and func_02012468 "just released". func_02012354 builds the word as
// ((KEYINPUT | *(u16*)0x027fffa8) ^ 0x2fff) & 0x2fff, so the ARM7 mirror puts X at 0x400 and Y at
// 0x800 beside the KEYINPUT bits the single-bit siblings at 0x02012390-0x0201241c test; L, R and
// 0x2000 ride along too. func_0201248c passes its own block and layers key repeat on top.
extern "C" ARM int AreButtonsHeld(unsigned short* obj, int mask) {
    return (*obj & mask) != 0;
}
