// WaitByLoop is a BIOS syscall stub at 0x02000466, inside the DS secure area.
//
// This file covers 0x02000464..0x0200046c rather than just the stub. dsd's lcf template
// concatenates delinked objects under ALIGNALL(4) and states no addresses, so an object whose
// range does not begin AND end on a 4-byte boundary makes the linker pad and shifts every byte
// of the ROM after it -- delinking one of these alone moved every downstream symbol by +4.
//
// The .short values are secure-area fill, copied from the ROM. They are not code and nothing
// reaches them; they are here so this object's range lands on 4-byte boundaries.
// Assembly rather than C because mwccarm has no 16-bit data directive and exports only one
// symbol per asm function, and WaitByLoop needs its own symbol at 0x02000466.

	.section .text
	.thumb

	.global data_02000464
data_02000464:
	.short 0x932c

	.global WaitByLoop
WaitByLoop:
	swi 3
	bx lr

	.global data_0200046a
data_0200046a:
	.short 0x6e48
