#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct Holder0209a97c;
struct Pair0209a97c;
void AppendPairToSlot0209a97c(struct Holder0209a97c* h, int slot, struct Pair0209a97c* src);

extern struct Holder0209a97c* data_02109ba8;

struct PairLocal0209a7bc {
    unsigned short a;
    unsigned short b;
};

// USA: func_0209a7bc
ARM int SubmitVariantPairAtSlot0209a7bc(void* arg) {
    int slot = GetIntFromVariant02030b0c((struct Variant02030b0c*)arg);
    struct PairLocal0209a7bc pair;
    pair.a = (unsigned short)GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)arg + 8));
    pair.b = (unsigned short)GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)arg + 0x10));
    AppendPairToSlot0209a97c(data_02109ba8, slot, (struct Pair0209a97c*)&pair);
    return 1;
}
