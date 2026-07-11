#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct Global020fdc20_d4ec {
    int pad0;
    int pad4;
    unsigned char* obj; // 0x8
};
extern struct Global020fdc20_d4ec data_020fdc20;

// USA: func_0201d4ec
ARM int PackRgb555ToField0x7e(struct Variant02030b0c* v) {
    int a = GetIntFromVariant02030b0c(v);
    int b = GetIntFromVariant02030b0c(v + 1);
    int c = GetIntFromVariant02030b0c(v + 2);
    *(unsigned short*)(data_020fdc20.obj + 0x7e) = a | (b << 5) | (c << 10);
    return 1;
}
