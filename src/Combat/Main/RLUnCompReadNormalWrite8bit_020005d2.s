// RLUnCompReadNormalWrite8bit is a BIOS syscall stub at 0x020005d2, inside the DS secure area.
//
// This file covers 0x020005d0..0x020005d8 rather than just the stub. dsd's lcf template
// concatenates delinked objects under ALIGNALL(4) and states no addresses, so an object whose
// range does not begin AND end on a 4-byte boundary makes the linker pad and shifts every byte
// of the ROM after it -- delinking one of these alone moved every downstream symbol by +4.
//
// The .short values are secure-area fill, copied from the ROM. They are not code and nothing
// reaches them; they are here so this object's range lands on 4-byte boundaries.
// Assembly rather than C because mwccarm has no 16-bit data directive and exports only one
// symbol per asm function, and RLUnCompReadNormalWrite8bit needs its own symbol at 0x020005d2.

	.section .text
	.thumb

	.global data_020005d0
data_020005d0:
	.short 0x82d3

	.global RLUnCompReadNormalWrite8bit
RLUnCompReadNormalWrite8bit:
	swi 0x14
	bx lr

	.global data_020005d6
data_020005d6:
	.short 0xbd9d
