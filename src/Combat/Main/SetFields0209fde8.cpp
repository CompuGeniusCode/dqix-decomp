#include <globaldefs.h>

struct Struct0209fde8 {
    char pad[0x6c];
    int f6c;
    char pad2[0x14];
    int f84;
    int f88;
};

// USA: func_0209fde8
ARM void SetFields0209fde8(struct Struct0209fde8* p, int a, int b, int c) {
    p->f84 = a;
    p->f88 = c;
    p->f6c = b;
}
