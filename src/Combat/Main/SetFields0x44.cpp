#include <globaldefs.h>

struct Fields020407b4 {
    char unk0[0x44];
    int field44;
    int field48;
    int field4c;
};

// USA: func_020407b4
ARM void SetFields0x44(struct Fields020407b4* dst, int a, int b, int c) {
    dst->field44 = a;
    dst->field48 = b;
    dst->field4c = c;
}
