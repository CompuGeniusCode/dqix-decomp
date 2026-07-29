#include <globaldefs.h>

// SKIP attempt func_020c6938: file name in build/usa/asm/main is
// GxLoadMatrix4x4.s. Target does ldmia r0!,{r2-r8,ip} (8 words, src
// auto-increment) then stmia r1,{r2-r8,ip} WITHOUT writeback -- TWICE, both
// stmia writing the same fixed r1 address. That is a GX command FIFO burst
// write (hardware register poke, second store legitimately overwrites/reuses
// the same MMIO address), not a memory copy. Explicit hand-asm-only skip
// category (worker_ov_all.md "Do NOT": GX-FIFO). No C construct produces a
// non-writeback repeated stmia to a fixed address. NOT a match, no
// // USA: tag.
