#include <globaldefs.h>

unsigned int DisableSpecificInterrupts(unsigned int mask);

struct IntState020d8654 {
    unsigned char field_0;
    unsigned char pad1[3];
    unsigned int field_4;
};
extern IntState020d8654 data_0214e4a0;

// Disables the LCD V-counter-match interrupt (IE bit 2, IRQ_MASK_LCD_VCOUNTER_MATCH) and remembers
// whether it had been on, so the pair at 0x020d8694 can put it back exactly as it was. The saved
// states are a bit stack, not a single flag: the word at data_0214e4a0+4 shifts left here and right
// on release, so suspends nest, and nothing bounds the depth -- past 32 the oldest is lost.
// data_0214e4a0 is shared with the 3D presentation code -- func_020d86d0 writes SWAP_BUFFERS at
// 0x04000540 and flips the parity byte at +0x0 -- presumably why this interrupt is the one held off.
extern "C" ARM void SuspendVCountMatchIrq(void) {
    data_0214e4a0.field_4 <<= 1;
    unsigned int old = DisableSpecificInterrupts(4);
    data_0214e4a0.field_4 |= (old & 4) ? 1 : 0;
}
