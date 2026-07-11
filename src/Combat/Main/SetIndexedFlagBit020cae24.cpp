#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);

extern int data_021116a8[];

struct RegBlock020cae24 {
    char pad[0x388];
    unsigned int bits;
};

// USA: func_020cae24
ARM void SetIndexedFlagBit020cae24(int index, int value) {
    unsigned int mask = DisableInterrupts();
    struct RegBlock020cae24* reg = (struct RegBlock020cae24*)0x27ffc00;
    data_021116a8[index] = value;
    if (value != 0) {
        reg->bits |= (1u << index);
    } else {
        reg->bits &= ~(1u << index);
    }
    RestoreInterrupts(mask);
}
