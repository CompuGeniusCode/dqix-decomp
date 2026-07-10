#include <globaldefs.h>

void WriteGXFifoZeroBurst(volatile void* fifo);

// USA: func_020c5354
ARM void FlushGXFifoAndWaitGeometryIdle(void) {
    WriteGXFifoZeroBurst((volatile void*)0x4000400);
    while (*(volatile unsigned int*)0x4000600 & 0x8000000);
}
