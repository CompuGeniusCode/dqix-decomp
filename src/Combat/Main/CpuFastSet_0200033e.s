// CpuFastSet is a BIOS syscall stub at 0x0200033e, inside the DS secure area.
//
// This file covers 0x0200033c..0x02000344 rather than just the stub. dsd's lcf template
// concatenates delinked objects under ALIGNALL(4) and states no addresses, so an object whose
// range does not begin AND end on a 4-byte boundary makes the linker pad and shifts every byte
// of the ROM after it -- delinking one of these alone moved every downstream symbol by +4.
//
// The .short values are secure-area fill, copied from the ROM. They are not code and nothing
// reaches them; they are here so this object's range lands on 4-byte boundaries.
// Assembly rather than C because mwccarm has no 16-bit data directive and exports only one
// symbol per asm function, and CpuFastSet needs its own symbol at 0x0200033e.

	.section .text
	.thumb

	.global data_0200033c
data_0200033c:
	.short 0xdc80

	.global CpuFastSet
CpuFastSet:
	swi 0xc
	bx lr

	.global data_02000342
data_02000342:
	.short 0xff76
