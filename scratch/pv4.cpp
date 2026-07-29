#include <globaldefs.h>
int GetObjectValue020db2dc(int a, int b);
struct PackedEntry020db6e4 {
    unsigned int word;
    union {
        unsigned short raw;
        struct {
            unsigned short lo10 : 10;
            unsigned short field2 : 2;
            unsigned short hi4 : 4;
        } bits;
    } h;
};
ARM void Test(void* obj, int b) {
    struct PackedEntry020db6e4* arr = (struct PackedEntry020db6e4*)GetObjectValue020db2dc((int)obj, *((unsigned char*)obj + 0x3c));
    unsigned short flags = (unsigned short)(b | 0xf800);
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            struct PackedEntry020db6e4* e = &arr[i * 4 + j + 16];
            e->word = 0xC0000000 | (unsigned char)(i << 6) | ((j & 7) << 22);
            e->h.raw = flags;
            e->h.bits.field2 = 2;
        }
    }
}
