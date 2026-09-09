#include <globaldefs.h>

extern "C" void func_0205addc(void* obj, unsigned char idx);

struct Header0205ae8c {
    char pad[4];
    unsigned short count;
};

// Walks every animation sequence in the bank at +0x3c and applies it. That bank is filled by the
// 'RNAN' branch of the resource dispatcher at 0x0205a528, which recognises the reversed NITRO
// magics NCER, NANR, NCGR and NCLR; func_0205a984 allocates one 0x18-byte record per sequence and
// stores the count at +4, which is the count this loop reads. func_0205addc does the per-sequence
// work, writing the sequence's x and y as fix32 (<<12) into the cell its current frame points at,
// in the cell array at +0x40 the 'RECN' branch built. Sequences with bit 3 of +0x15 clear are skipped.
extern "C" ARM void ApplyAllCellAnimations(void* obj) {
    unsigned short count;
    struct Header0205ae8c* h;
    unsigned short i;

    h = *(struct Header0205ae8c**)((char*)obj + 0x3c);
    if (h == 0) {
        return;
    }
    count = h->count;
    i = 0;
    while (i < count) {
        func_0205addc(obj, (unsigned char)i);
        i++;
    }
}
