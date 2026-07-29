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
    unsigned short flags = b | 0xf800;
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            int idx = i * 4 + j + 16;
            arr[idx].word = 0xC0000000 | (unsigned char)(i << 6) | ((j & 7) << 22);
            arr[idx].h.raw = flags;
            arr[idx].h.bits.field2 = 2;
        }
    }
}
