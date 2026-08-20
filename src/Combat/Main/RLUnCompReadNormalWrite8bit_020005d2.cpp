#include <globaldefs.h>

// USA: func_020005d0
//
// RLUnCompReadNormalWrite8bit is a BIOS syscall stub at 0x020005d2, inside the secure area. Its own range is not
// 4-aligned at both ends, and dsd's lcf concatenates delinked objects under ALIGNALL(4),
// so delinking it alone makes the linker pad and shifts every byte after it in the ROM.
// This file therefore covers 0x020005d0..0x020005d8: the stub plus the neighbouring
// secure-area fill, byte for byte. The fill is not code; it is spelled as the THUMB
// instructions that encode to exactly those ROM bytes, because mwccarm has dcd but no dcw.
// Nothing reaches any of it: there are zero relocations into 0x02000000-0x02000800.
extern "C" THUMB
asm void data_020005d0(void)
{
    strh r3, [r2, #0x16]
    swi 0x14
    bx lr
    pop {r0, r2, r3, r4, r7, pc}
}
