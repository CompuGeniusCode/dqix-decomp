#include <globaldefs.h>

// USA: func_020c56dc
// Writes 32 four-word zero bursts to the geometry command FIFO (r0 = 0x4000400).
ARM void WriteGXFifoZeroBurst(volatile void* fifo) {
    asm {
        mov r1, #0
        mov r2, #0
        mov r3, #0
        mov ip, #0
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
        stmia r0, {r1, r2, r3, ip}
    }
}
