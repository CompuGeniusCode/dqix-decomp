#include <globaldefs.h>

int IsField0xcZero(unsigned short* obj);

struct WrapCtx020bb964 { int unk_0; unsigned int modulus; };
unsigned short WrapIndexModField020bb964(WrapCtx020bb964* ctx, unsigned int value);

struct Ring020bbc78 {
    char pad[8];
    unsigned short head;    // +0x8
    unsigned short pad_a;   // +0xa
    unsigned short count;   // +0xc
};

// USA: func_020bbc78
ARM int AdvanceRing020bbc78(Ring020bbc78* ring) {
    if (IsField0xcZero((unsigned short*)ring)) return 0;
    ring->head = WrapIndexModField020bb964((WrapCtx020bb964*)ring, ring->head);
    ring->count--;
    return 1;
}
