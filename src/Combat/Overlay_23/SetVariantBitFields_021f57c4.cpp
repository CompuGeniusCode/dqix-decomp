#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct PackedBits021f57c4 {
    unsigned int low : 12;
    unsigned int mid : 4;
    unsigned int hi : 5;
    unsigned int rest : 11;
};

struct StructWithOffset100_021f57c4 {
    char pad[0x100];
    struct PackedBits021f57c4 bits;
};

struct Data021fff08_021f57c4 {
    char pad2[0xc];
    struct StructWithOffset100_021f57c4* ptr;
};

extern struct Data021fff08_021f57c4 data_ov023_021fff08;

// USA: func_ov023_021f57c4  (semantic: SetVariantBitFields_021f57c4)
extern "C" ARM int func_ov023_021f57c4(void* objRaw) {
    struct Variant02030b0c* obj = (struct Variant02030b0c*)objRaw;
    data_ov023_021fff08.ptr->bits.low = GetIntFromVariant02030b0c(obj);
    data_ov023_021fff08.ptr->bits.mid = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)obj + 8));
    data_ov023_021fff08.ptr->bits.hi = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)obj + 0x10));
    return 1;
}
