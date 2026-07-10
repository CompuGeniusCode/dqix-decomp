#include <globaldefs.h>

struct Variant02030b0c { int tag; int u; };
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

extern int data_02108e40;

// USA: func_0207a558
ARM int AccumulateVariantFlagsField0207a558(struct Variant02030b0c* p, int n) {
    unsigned char acc = 0;
    int i;
    for (i = 0; i < n; i++) {
        acc = (acc | GetIntFromVariant02030b0c(p++)) & 0xff;
    }
    unsigned char* dst = *(unsigned char**)((char*)&data_02108e40 + 8);
    dst[0x14] = (dst[0x14] & ~0x78) | ((acc & 0xf) << 3);
    return 1;
}
