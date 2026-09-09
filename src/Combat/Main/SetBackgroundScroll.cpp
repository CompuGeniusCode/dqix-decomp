#include <globaldefs.h>

extern int (*data_020f01b8[][4])(int, int);

struct Obj0204b5e8 {
    char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

// Writes BGxHOFS/BGxVOFS for the layer this descriptor names. The byte at +0x1c is two nibbles:
// the low one picks the 2D engine and the high one the background, and data_020f01b8[engine][bg]
// is the table of one-line setters -- [0][0] stores to 0x04000010, [1][3] to 0x0400101c. Each
// setter masks both offsets to nine bits and packs them into a single word write. The eight
// entries after those, from 0x020f01d8, are the matching BGxCNT priority setters, reached by
// func_0204b5b4, which indexes that table with the same nibbles and passes priority & 3.
extern "C" ARM int SetBackgroundScroll(struct Obj0204b5e8* obj, int a, int b) {
    return data_020f01b8[obj->lo][obj->hi](a, b);
}
