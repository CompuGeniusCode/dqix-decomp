#include <globaldefs.h>

struct Struct020A8218;
void AllocateArray020a8218(struct Struct020A8218*, int, int);

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c*);

struct AllocContext020a7f5c {
    int enable;                  // 0x0
    struct Struct020A8218* out;  // 0x4
};
extern struct AllocContext020a7f5c data_02109fe0;

// USA: func_020a7f5c
ARM int AllocateFromVariant020a7f5c(struct Variant02030b0c* variant) {
    unsigned short count = (unsigned short)GetIntFromVariant02030b0c(variant);
    AllocateArray020a8218(data_02109fe0.out, data_02109fe0.enable, count);
    return 1;
}
