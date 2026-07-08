#include <globaldefs.h>

struct GridMap {
    char pad0[6];
    unsigned short width;
    char pad8[4];
    int bits[1];
};

struct GridOwner {
    int yFixed;
    char pad4[4];
    struct GridMap* map;
};

// USA: func_020b9978
ARM void ReadGridBit(int* out, struct GridOwner* owner, int x) {
    struct GridMap* map = owner->map;
    unsigned int bitIndex = (owner->yFixed >> 12) * map->width + x;
    *out = map->bits[bitIndex >> 5] & (1 << (bitIndex & 0x1f));
}
