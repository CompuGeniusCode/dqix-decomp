#include <globaldefs.h>

// Sets the per-slot byte at +0x902 of the global message parameter block that ResetMessageBuilder
// clears and FormatMessageText formats from. Callers fill a numeric slot as a trio: the value into
// the int array at +0x8b0, 1 into the byte array at +0x8f1, and this. The byte tracks the
// magnitude of the value, not the call site -- 7 for the gold field at combatant+0xf6c, 0xa for
// the wider +0xf74, 4 for a u16, 2 for a byte, 3 for the ov013 counters, and func_ov023_021e83c8
// passes a runtime value -- so presumably a digit count; no consumer of the array is decompiled.
extern "C" ARM void SetMessageNumberDigits(unsigned char* base, int index, unsigned char value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        (base + index)[0x902] = value;
    }
}
