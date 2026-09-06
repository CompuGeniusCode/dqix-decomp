#include <globaldefs.h>

struct Reloc02b02d0 {
    unsigned short count;
    unsigned short pad;
    unsigned int *arr;
};

void RelocateOffsetArray(struct Reloc02b02d0 *h);

// USA: func_020b0094
ARM void RelocateOffsetArrayAtOffset8(char *base) {
    RelocateOffsetArray((struct Reloc02b02d0 *)(base + 8));
}
