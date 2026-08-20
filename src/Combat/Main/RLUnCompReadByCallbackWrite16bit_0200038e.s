// RLUnCompReadByCallbackWrite16bit is a BIOS syscall stub at 0x0200038e, inside the DS secure area.
//
// This file covers 0x0200038c..0x02000394 rather than just the stub. dsd's lcf template
// concatenates delinked objects under ALIGNALL(4) and states no addresses, so an object whose
// range does not begin AND end on a 4-byte boundary makes the linker pad and shifts every byte
// of the ROM after it -- delinking one of these alone moved every downstream symbol by +4.
//
// The .short values are secure-area fill, copied from the ROM. They are not code and nothing
// reaches them; they are here so this object's range lands on 4-byte boundaries.
// Assembly rather than C because mwccarm has no 16-bit data directive and exports only one
// symbol per asm function, and RLUnCompReadByCallbackWrite16bit needs its own symbol at 0x0200038e.

	.section .text
	.thumb

	.global data_0200038c
data_0200038c:
	.short 0x7a26

	.global RLUnCompReadByCallbackWrite16bit
RLUnCompReadByCallbackWrite16bit:
	swi 0x15
	bx lr

	.global data_02000392
data_02000392:
	.short 0xbc97
