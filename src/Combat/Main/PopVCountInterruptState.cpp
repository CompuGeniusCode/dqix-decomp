#include <globaldefs.h>

unsigned int EnableSpecificInterrupts(unsigned int mask);
unsigned int DisableSpecificInterrupts(unsigned int mask);

struct IntState020d8654 {
    unsigned char field_0;
    unsigned char pad1[3];
    unsigned int field_4;
};
extern IntState020d8654 data_0214e4a0;

// Restores the V-counter-match interrupt to whatever the matching push at SuspendVCountMatchIrq saved, then
// drops that bit. Mask 4 is IRQ_MASK_LCD_VCOUNTER_MATCH, and data_0214e4a0+4 is a shift register, so
// the pair nests up to 32 deep, and the push and the pop have exactly the same fifteen callers. They
// bracket short critical sections: func_0205e18c, func_0205e1e4 and func_0205e41c, and the battle
// record shuffling in ResetBattleRecordFlags, func_0202c288 and ShiftRecords.
extern "C" ARM void PopVCountInterruptState(void) {
    if (data_0214e4a0.field_4 & 1) {
        EnableSpecificInterrupts(4);
    } else {
        DisableSpecificInterrupts(4);
    }
    data_0214e4a0.field_4 >>= 1;
}
