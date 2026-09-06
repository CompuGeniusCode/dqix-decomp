// Div is a BIOS syscall stub at 0x020006aa, inside the DS secure area.
//
// This file covers 0x020006a8..0x020006b0 rather than just the stub. dsd's lcf template
// concatenates delinked objects under ALIGNALL(4) and states no addresses, so an object whose
// range does not begin AND end on a 4-byte boundary makes the linker pad and shifts every byte
// of the ROM after it -- delinking one of these alone moved every downstream symbol by +4.
//
// The .short values are secure-area fill, copied from the ROM. They are not code and nothing
// reaches them; they are here so this object's range lands on 4-byte boundaries.
// Assembly rather than C because mwccarm has no 16-bit data directive and exports only one
// symbol per asm function, and Div needs its own symbol at 0x020006aa.

	.section .text
	.thumb

	.global data_020006a8
data_020006a8:
	.short 0xce16

	.global Div
Div:
	swi 9
	bx lr

	.global data_020006ae
data_020006ae:
	.short 0xbe35
