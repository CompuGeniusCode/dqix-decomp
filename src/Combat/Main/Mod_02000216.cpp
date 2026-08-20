#include <globaldefs.h>

// USA: func_02000214
//
// One object covering 0x02000214..0x0200021c so that BOTH ends sit on a 4-byte boundary, which is
// what dsd's ALIGNALL(4) lcf requires of a delinked file. The first halfword is secure-area fill,
// not code: it is spelled as the THUMB instruction that encodes to those exact ROM bytes because
// mwccarm's inline assembler has no halfword data directive (dcd works, dcw does not).
// The real BIOS stub `Mod` begins 2 bytes in, at 0x02000216.
extern "C" THUMB
asm void data_02000214(void)
{
    lsr r4, r4, #29     // 0x0f64 -- fill byte pair at 0x02000214, not reached
    swi 9               // Mod entry, 0x02000216
    add r0, r1, #0
    bx lr
}
