#include <globaldefs.h>

// USA: func_02000730
//
// Sqrt is a BIOS syscall stub at 0x02000732, inside the secure area. Its own range is not
// 4-aligned at both ends, and dsd's lcf concatenates delinked objects under ALIGNALL(4),
// so delinking it alone makes the linker pad and shifts every byte after it in the ROM.
// This file therefore covers 0x02000730..0x02000738: the stub plus the neighbouring
// secure-area fill, byte for byte. The fill is not code; it is spelled as the THUMB
// instructions that encode to exactly those ROM bytes, because mwccarm has dcd but no dcw.
// Nothing reaches any of it: there are zero relocations into 0x02000000-0x02000800.
extern "C" THUMB
asm void data_02000730(void)
{
    sub r2, #0xcc
    swi 0xd
    bx lr
    add r7, r5, #0
}
