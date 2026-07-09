#include <globaldefs.h>

struct Vec3_37774 {
    int a[3];
};

struct Src_37774 {
    char unk0[0x44];
    struct Vec3_37774 vec44;
    char unk50[0x34];
    int f84;
    char unk88[0x4];
    int f8c;
};

// USA: func_02037774
ARM void BuildVec3FromScatteredFields(struct Vec3_37774* dst, struct Src_37774* src) {
    struct Vec3_37774 tmp;
    tmp = src->vec44;
    tmp.a[0] = src->f84;
    tmp.a[2] = src->f8c;
    *dst = tmp;
}
