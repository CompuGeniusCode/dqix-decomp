#include <globaldefs.h>

struct Sub020989cc {
    char pad[0xb38];
    unsigned int field_b38;
    unsigned int field_b3c;
    unsigned char field_b40;
    unsigned char field_b41;
};

struct Base020989cc {
    char pad[0x1000];
    struct Sub020989cc sub;
};

// USA: func_020989cc
ARM void UpdateRankLevel020989cc(struct Base020989cc* base) {
    unsigned int v;
    unsigned char rank;
    if (base->sub.field_b3c == 6) return;
    v = base->sub.field_b38;
    if (v < 7) base->sub.field_b41 = 1;
    else if (v >= 7 && v < 0xd) base->sub.field_b41 = 2;
    else if (v >= 0xd && v < 0x13) base->sub.field_b41 = 3;
    else if (v >= 0x13 && v < 0x19) base->sub.field_b41 = 4;
    else if (v >= 0x19 && v < 0x1e) base->sub.field_b41 = 5;
    else if (v >= 0x1e) base->sub.field_b41 = 6;
    rank = base->sub.field_b41;
    if (rank > base->sub.field_b3c) base->sub.field_b3c = base->sub.field_b3c + 1;
}
