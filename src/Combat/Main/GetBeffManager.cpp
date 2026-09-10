#include <globaldefs.h>

extern int data_021079ec;

// Returns the one beff manager, the static at data_021079ec that the constructor at 0x02058704
// builds from __sinit_020e5eb4: sixteen 0xd4-byte records from +0x8, each of which occupies a
// combatant slot - func_02058658 (0x02058658) maps combatant ids 0xd0..0xdf onto
// them, and func_02057f00 walks the same sixteen and calls ClearCombatantSlot on every one whose
// owner value at +0xd0 matches. The records end at +0xd48, but func_02057930 also zeroes +0xd4c
// and +0xd50 and the next bss symbol is 0x02108740, so the object is 0xd54 bytes. A linked list
// hangs off +0x0, keyed by the word at each node's +0 with the next pointer at +0x1ec
// (func_02057f8c walks it).
// The module loads ".beff" entries out of a NARC and hangs the models off combatant bones; the
// bone names "head", "waist", "chest", "arm1L" and the "in"/"loop"/"out" clip labels sit next to
// that string in rodata at 0x020f047e-0x020f04b8, and the nodes this list holds have the same
// +0x1ec link as the ones curated LoadEb04Models builds out of "eb0400.chr". So beff is
// presumably "battle effect", but the expansion is not established and the ROM's own spelling is
// kept.
extern "C" ARM void* GetBeffManager(void) {
    return &data_021079ec;
}
