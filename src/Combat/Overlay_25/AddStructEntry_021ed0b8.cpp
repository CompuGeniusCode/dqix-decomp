#include <globaldefs.h>

struct Struct021ecb90 {
    int a;
    unsigned char b, c, d;
    int e, f, g, h, i, j;
    short k, l;
    int m, n;
    unsigned short o, p, q, r, s, t;
    unsigned char u, v, w;
    unsigned short x;
};

void CopyStructFields_021ecb90(struct Struct021ecb90* dst, struct Struct021ecb90* src);

struct Container021ed0b8 {
    struct Struct021ecb90 arr[12];
    unsigned char count;
};

// USA: func_ov025_021ed0b8  (semantic: AddStructEntry_021ed0b8)
extern "C" ARM void func_ov025_021ed0b8(struct Container021ed0b8* obj, struct Struct021ecb90* src) {
    int i;
    for (i = 0; i < 12; i++) {
        if (obj->arr[i].a == 0) {
            CopyStructFields_021ecb90(&obj->arr[i], src);
            obj->count++;
            return;
        }
    }
}
